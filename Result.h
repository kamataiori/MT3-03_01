#pragma once
#include "MathFunc.h"

//static const int kWindowWidth = 1280;
//static const int kWindowHeight = 720;

class Result
{
public:

	//Sphere sphere
	//{
	//	0,0,0, //center
	//	1, // radius
	//	(int)WHITE, 
	//};

	/*Sphere sphere2
	{
		1.6f, 0,0,
		0.3f,
		(int)WHITE
	};*/

	/*Plane plane
	{
		0.0f,1.0f,0.0f,
		1.0f
	};*/

	/*Vector3 controlPoints[3]
	{
		{-0.8f, 0.58f, 1.0f},
		{1.76f, 1.0f, -0.3f},
		{0.94f, -0.7f, 2.3f}
	};*/

	/*Vector3 controlPoints[4]
	{
		{-0.8f, 0.58f, 1.0f},
		{1.76f, 1.0f, -0.3f},
		{0.94f, -0.7f, 2.3f},
		{-0.53f, -0.26f, -0.15f}
	};*/

	//Vector3 cameraRotate{ 0.26f, 0.0f, 0.0f };
	//Vector3 cameraTranslate{ 0.0f,1.9f, -6.49f };
	Vector3 cameraRotate{ 0.0f,0.0f,0.0f };

	Vector3 cameraTranslate{ 0.0f,0.0f,0.0f };
	//Vector3 cameraPosition = { 0,0,-10.0f };

	//Segment segment
	//{
	//	{-0.7f, 0.3f, 0.0f}, //origin
	//	{2.0f, -0.5f, 0.0f}, //diff
	//	(int)WHITE
	//
	//};
	//
	//Triangle triangle
	//{
	//	{0.0f,1.0f,0.0f,
	//	1.0f,-1.0f,0.0f,
	//	-1.0f,-1.0f,0.0f},
	//	(int)WHITE
	//};

	//Vector3 point{ -1.5f, 0.6f, 0.6f };

	/*AABB aabb1{
		.min{-0.5f, -0.5f, -0.5f},
		.max{0.5f, 0.5f, 0.5f}
	};*/

	//AABB aabb2{
	//	.min{0.2f, 0.2f, 0.2f},
	//	.max{1.0f, 1.0f, 1.0f},
	//	.color{(int)WHITE}
	//};

	Vector3 translates[3] = //0 = shoulder, 1 = elbow, 2 = hand
	{
		{0.2f, 1.0f, 0.0f},
		{0.4f, 0.0f, 0.0f},
		{0.3f, 0.0f, 0.0f}
	};

	Vector3 rotates[3] =
	{
		{0.0f, 0.0f, -6.8f},
		{0.0f, 0.0f, -1.4f},
		{0.0f, 0.0f, 0.0f}
	};

	Vector3 scales[3] =
	{
		{1.0f, 1.0f, 1.0f},
		{1.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f}
	};

	float radius = 10.0f;
	float theta = -3.46f;
	float phi = 1.5f;



	Vector3 cameraPosition = SphericalToCartesian(radius, theta, phi);
	Vector3 cameraTarget = { 0.0f, 0.0f, 0.0f };
	Vector3 cameraUp = { 0.0f, 1.0f, 0.0f };


	Matrix4x4 viewMatrix = MakeLookAtMatrix4x4(cameraPosition, cameraTarget, cameraUp);
	Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
	Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
	Matrix4x4 viewMatrixProjectionMatrix = Multiply(viewMatrix, projectionMatrix);


	Matrix4x4 shoulderMatrix = MakeAffineMatrix(scales[0], rotates[0], translates[0]);
	Matrix4x4 elbowMatrix = MakeAffineMatrix(scales[1], rotates[1], translates[1]);
	Matrix4x4 handMatrix = MakeAffineMatrix(scales[2], rotates[2], translates[2]);

	Matrix4x4 shoulderWorldMatrix = shoulderMatrix;
	Matrix4x4 elbowWorldMatrix = Multiply(elbowMatrix, shoulderWorldMatrix);
	Matrix4x4 handWorldMatrix = Multiply(handMatrix, elbowWorldMatrix);

	//Vector3 start = Transform(Transform(segment.origin, viewMatrixProjectionMatrix), viewportMatrix);
	//Vector3 end =Transform(Transform(Add(segment.origin, segment.diff), viewMatrixProjectionMatrix), viewportMatrix);

	Vector3 shoulderPosition = { shoulderWorldMatrix.m[3][0], shoulderWorldMatrix.m[3][1], shoulderWorldMatrix.m[3][2] };
	Vector3 elbowPosition = { elbowWorldMatrix.m[3][0], elbowWorldMatrix.m[3][1], elbowWorldMatrix.m[3][2] };
	Vector3 handPosition = { handWorldMatrix.m[3][0], handWorldMatrix.m[3][1], handWorldMatrix.m[3][2] };
	Vector3 shoulderLinePosition = Transform(Transform(shoulderPosition, viewProjectionMatrix), viewportMatrix);
	Vector3 elbowLinePosition = Transform(Transform(elbowPosition, viewProjectionMatrix), viewportMatrix);
	Vector3 handLinePosition = Transform(Transform(handPosition, viewProjectionMatrix), viewportMatrix);






	void Initialize();

	void Update();

	void Draw();
};

