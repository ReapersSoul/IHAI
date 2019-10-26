#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"
#include "cinder/log.h"

#include <math.h>

#include "Mesh.h"
#include "Human.h"

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

	Human H;

	/*
	//cinder stuff
	params::InterfaceGlRef		mParams;
	CameraPersp		mCam;
	float scale=1;
	Color col=Color(1,0,0);
	//cam settings
	vec3 lookingAt=vec3(0);
	vec3 camPos = vec3(10,10,10);
	//mesh
	TriMesh mesh;*/
};

void IHAIApp::setup()
{
	/*
	log::makeLogger<log::LoggerFile>("/tmp/cinder/cinder.log");
	ml.LoadMesh("C:/Users/Trevor/Desktop/untitled.ALobj");
	for (int i = 0; i < ml.bones.size(); i++) {
		CI_LOG_D("bone #");
		CI_LOG_D(i);
		CI_LOG_D("\n");
		CI_LOG_D(ml.bones[i].posX);
		CI_LOG_D(ml.bones[i].posY);
		CI_LOG_D(ml.bones[i].posZ);
		CI_LOG_D(ml.bones[i].xRot);
		CI_LOG_D(ml.bones[i].yRot);
		CI_LOG_D(ml.bones[i].zRot);
		CI_LOG_D(ml.bones[i].HasParent);
		CI_LOG_D(ml.bones[i].parent);
	}
	for (int i = 0; i < ml.points.size(); i++) {
		CI_LOG_D("living point #" << i << ": ");
		CI_LOG_D(ml.points[i].posX);
		CI_LOG_D(ml.points[i].posY);
		CI_LOG_D(ml.points[i].posZ);
		CI_LOG_D(ml.points[i].pain);
		CI_LOG_D(ml.points[i].pleasure);
		CI_LOG_D(ml.points[i].presure);
		CI_LOG_D(ml.points[i].Parent_Bone);
		CI_LOG_D(ml.points[i].weight);
	}
	for (int i = 0; i < ml.faces.size(); i++) {
		CI_LOG_D("face #");
		CI_LOG_D(i);
		CI_LOG_D("\n");
		for (int j = 0; j < ml.faces[i].size(); j++) {
			CI_LOG_D(ml.faces[i][j]);
		}
		CI_LOG_D("\n");
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
	*/
}

void IHAIApp::mouseDown( MouseEvent event )
{
	H.run();
}

void IHAIApp::mouseDrag(MouseEvent event)
{
}

void IHAIApp::update()
{
	//mCam.lookAt(camPos, lookingAt);
}

void IHAIApp::draw()
{
	/*
	gl::clear();
	gl::enableDepthRead();
	gl::enableDepthWrite();

	gl::setMatrices(mCam);

	for (int i = 0; i < ml.points.size(); i++) {
		vec3 tmpvec = vec3(ml.points[i].posX, ml.points[i].posY, ml.points[i].posZ);
		gl::drawSphere(tmpvec* scale, radius, segments);
	}

	//draw mesh


	gl::draw(mesh);

	mParams->draw();
	*/

}

CINDER_APP( IHAIApp, RendererGl )
