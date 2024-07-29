#include "Result.h"

void Result::Initialize()
{

}

void Result::Update()
{
	//Vector3 cameraPosition = SphericalToCartesian(radius, theta, phi);
	//Vector3 cameraTarget = { 0.0f, 0.0f, 0.0f };
	//Vector3 cameraUp = { 0.0f, 1.0f, 0.0f };


	//Matrix4x4 viewMatrix = MakeLookAtMatrix4x4(cameraPosition, cameraTarget, cameraUp);
	//Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	//Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	//Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	//Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
	//Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

	//Matrix4x4 shoulderMatrix = MakeAffineMatrix(scales[0], rotates[0], translates[0]);
	//Matrix4x4 elbowMatrix = MakeAffineMatrix(scales[1], rotates[1], translates[1]);
	//Matrix4x4 handMatrix = MakeAffineMatrix(scales[2], rotates[2], translates[2]);

	//Matrix4x4 shoulderWorldMatrix = shoulderMatrix;
	//Matrix4x4 elbowWorldMatrix = Multiply(elbowMatrix, shoulderWorldMatrix);
	//Matrix4x4 handWorldMatrix = Multiply(handMatrix, elbowWorldMatrix);

	////Vector3 start = Transform(Transform(segment.origin, viewMatrixProjectionMatrix), viewportMatrix);
	////Vector3 end =Transform(Transform(Add(segment.origin, segment.diff), viewMatrixProjectionMatrix), viewportMatrix);

	//Vector3 shoulderPosition = { shoulderWorldMatrix.m[3][0], shoulderWorldMatrix.m[3][1], shoulderWorldMatrix.m[3][2] };
	//Vector3 elbowPosition = { elbowWorldMatrix.m[3][0], elbowWorldMatrix.m[3][1], elbowWorldMatrix.m[3][2] };
	//Vector3 handPosition = { handWorldMatrix.m[3][0], handWorldMatrix.m[3][1], handWorldMatrix.m[3][2] };
	//Vector3 shoulderLinePosition = Transform(Transform(shoulderPosition, viewProjectionMatrix), viewportMatrix);
	//Vector3 elbowLinePosition = Transform(Transform(elbowPosition, viewProjectionMatrix), viewportMatrix);
	//Vector3 handLinePosition = Transform(Transform(handPosition, viewProjectionMatrix), viewportMatrix);
	
}

void Result::Draw()
{
	DrawGrid(viewMatrixProjectionMatrix, viewportMatrix);

		
	DrawSphere({ shoulderPosition, 0.1f }, viewProjectionMatrix, viewportMatrix, RED);
	DrawSphere({ elbowPosition, 0.1f }, viewProjectionMatrix, viewportMatrix, BLUE);
	DrawSphere({ handPosition, 0.1f }, viewProjectionMatrix, viewportMatrix, GREEN);

	Novice::DrawLine((int)shoulderLinePosition.x, (int)shoulderLinePosition.y, (int)elbowLinePosition.x, (int)elbowLinePosition.y, WHITE);
	Novice::DrawLine((int)elbowLinePosition.x, (int)elbowLinePosition.y, (int)handLinePosition.x, (int)handLinePosition.y, WHITE);

	DrawGrid(viewProjectionMatrix, viewportMatrix);

	ImGui::Begin("Window");
	/*ImGui::DragFloat("theta", &theta, 0.01f);
	ImGui::DragFloat("phi", &phi, 0.01f);*/
	ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
	ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
	ImGui::DragFloat3("Shoulder Translate", &translates[0].x, 0.01f);
	ImGui::DragFloat3("Shoulder Rotate", &rotates[0].x, 0.01f);
	ImGui::DragFloat3("Shoulder Scale", &scales[0].x, 0.01f);
	ImGui::DragFloat3("Elbow Translate", &translates[1].x, 0.01f);
	ImGui::DragFloat3("Elbow Rotate", &rotates[1].x, 0.01f);
	ImGui::DragFloat3("Elbow Scale", &scales[1].x, 0.01f);
	ImGui::DragFloat3("Hand Translate", &translates[2].x, 0.01f);
	ImGui::DragFloat3("Hand Rotate", &rotates[2].x, 0.01f);
	ImGui::DragFloat3("Hand Scale", &scales[2].x, 0.01f);
	//ImGui::DragFloat3("shoulder pos", &shoulderPos.x, 0.01f);
	//ImGui::DragFloat3("elbow pos", &elbowPos.x, 0.01f);
	ImGui::End();
}
