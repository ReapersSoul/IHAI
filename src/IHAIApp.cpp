#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"
#include "cinder/Arcball.h"

#include <math.h>

#include "Mesh.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class IHAIApp : public App {
  public:
	//my variables and functions
	  Mesh ml;
	// cinder functions
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void mouseDrag(MouseEvent event) override;
	void update() override;
	void draw() override;
	//cinder stuff
	params::InterfaceGlRef		mParams;
	CameraPersp		mCam;
	float scale=1;
	Color col=Color(1,0,0);
	//cam settings
	vec3 lookingAt=vec3(0);
	vec3 camPos = vec3(10,10,10);
	//mesh
	TriMesh mesh;
};

void IHAIApp::setup()
{
	ml.LoadMesh("C:/Users/Trevor/Desktop/untitled.ALobj");
	for (int i = 0; i < ml.bones.size(); i++) {
		cout << "bone #" << i << ": " << endl;
		cout << ml.bones[i].posX << endl;
		cout << ml.bones[i].posY << endl;
		cout << ml.bones[i].posZ << endl;
		cout << ml.bones[i].xRot << endl;
		cout << ml.bones[i].yRot << endl;
		cout << ml.bones[i].zRot << endl;
		cout << ml.bones[i].HasParent << endl;
		cout << ml.bones[i].parent << endl;
	}
	for (int i = 0; i < ml.points.size(); i++) {
		cout << "living point #" << i << ": " << endl;
		cout << ml.points[i].posX << endl;
		cout << ml.points[i].posY << endl;
		cout << ml.points[i].posZ << endl;
		cout << ml.points[i].pain << endl;
		cout << ml.points[i].pleasure << endl;
		cout << ml.points[i].presure << endl;
		cout << ml.points[i].Parent_Bone << endl;
		cout << ml.points[i].weight << endl;
	}
	for (int i = 0; i < ml.faces.size(); i++) {
		cout << "face #" << i << ": ";
		for (int j = 0; j < ml.faces[i].size(); j++) {
			cout << ml.faces[i][j] << " ";
		}
		cout << endl;
	}
	//cinder stuff
		//params stuff
	mParams = params::InterfaceGl::create(getWindow(), "CameraPersp", toPixels(ivec2(200, 300)));
	mParams->addParam("color", &col).step(0.01f);
	mParams->addParam("scale", &scale).step(0.01f);
	mParams->addSeparator();
	mParams->addText("Cam settings:");
	mParams->addParam("looking at", &lookingAt).step(0.5f);
	mParams->addParam("cam position", &camPos).step(0.5f);


	//mesh
	mesh = TriMesh(
		TriMesh::Format()
		.positions()
		.colors(3)
	);
	for (int i = 0; i < ml.points.size(); i++) {
		mesh.appendPosition(vec3(ml.points[i].posX*scale, ml.points[i].posY*scale, ml.points[i].posZ*scale));
		mesh.appendColorRgb(col);
	}

	for (int i = 0; i < ml.faces.size(); i++) {
		mesh.appendTriangle(ml.faces[i][0], ml.faces[i][1], ml.faces[i][2]);
	}
}

void IHAIApp::mouseDown( MouseEvent event )
{
}

void IHAIApp::mouseDrag(MouseEvent event)
{
}

void IHAIApp::update()
{
	mCam.lookAt(camPos, lookingAt);
}

void IHAIApp::draw()
{
	gl::clear();
	gl::enableDepthRead();
	gl::enableDepthWrite();

	gl::setMatrices(mCam);

	/*for (int i = 0; i < ml.points.size(); i++) {
		vec3 tmpvec = vec3(ml.points[i].posX, ml.points[i].posY, ml.points[i].posZ);
		gl::drawSphere(tmpvec* scale, radius, segments);
	}*/

	//draw mesh


	gl::draw(mesh);

	mParams->draw();
}

CINDER_APP( IHAIApp, RendererGl )
