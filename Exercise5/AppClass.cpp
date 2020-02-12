#include "AppClass.h"
void Application::InitVariables(void)
{
	//Make MyMesh object

	for (int i = 0; i < 47; i++)
	{
		m_pMesh = new MyMesh();
		m_pMesh->GenerateCube(2.0f, C_BLACK);
		meshList.push_back(m_pMesh);
	}
	

	//Make MyMesh object
	/*m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(1.0f, C_WHITE);*/
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));
	//m_pMesh1->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3( 3.0f, 0.0f, 0.0f)));


	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	vector3 translateAmount = vector3(-6.0f, 8.0f, 0.0f);
	//static float movement = 0;
	//matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f, 2.0f, 2.0f));
	//translateAmount.x += movement;
	matrix4 m4Translate = glm::translate(IDENTITY_M4, translateAmount);
	//matrix4 m4Model = ToMatrix4(m_qArcBall);

	matrix4 m4Model = m4Translate;

	meshList[0]->Render(m4Projection, m4View, m4Model);


	translateAmount.x = 6.0;
	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;

	meshList[1]->Render(m4Projection, m4View, m4Model);


	translateAmount.x = 6.0;
	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;

	meshList[1]->Render(m4Projection, m4View, m4Model);


	//new row
	translateAmount.y = 6;


	translateAmount.x = -4.0;
	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;

	meshList[2]->Render(m4Projection, m4View, m4Model);

	translateAmount.x = 4.0;
	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;

	meshList[3]->Render(m4Projection, m4View, m4Model);


	//new row
	translateAmount.y = 4;
	translateAmount.x = -6;

	for (int i = 0; i < 7; i++) {
		
		m4Translate = glm::translate(IDENTITY_M4, translateAmount);

		m4Model = m4Translate;
		meshList[4+i]->Render(m4Projection, m4View, m4Model);
		translateAmount.x += 2;
	}

	//new row 
	translateAmount.y = 2;
	translateAmount.x = -8;
	int counter = 2;

	for (int i = 0; i < 7; i++) {
		if (i == counter) {
			translateAmount.x += 2;
			counter = 5;
		}
		m4Translate = glm::translate(IDENTITY_M4, translateAmount);

		m4Model = m4Translate;
		meshList[11 + i]->Render(m4Projection, m4View, m4Model);
		translateAmount.x += 2;

	}

	//new row
	translateAmount.y = 0;
	translateAmount.x = -10;

	for (int i = 0; i < 11; i++) {

		m4Translate = glm::translate(IDENTITY_M4, translateAmount);

		m4Model = m4Translate;
		meshList[18 + i]->Render(m4Projection, m4View, m4Model);
		translateAmount.x += 2;
	}

	//new row 
	translateAmount.y = -2;
	translateAmount.x = -10;
	counter = 1;

	for (int i = 0; i < 9; i++) {
		if (i == counter) {
			translateAmount.x += 2;
			counter = 8;
		}
		m4Translate = glm::translate(IDENTITY_M4, translateAmount);

		m4Model = m4Translate;
		meshList[29 + i]->Render(m4Projection, m4View, m4Model);
		translateAmount.x += 2;

	}

	//new row
	translateAmount.y = -4;

	translateAmount.x = -10;

	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;
	meshList[38]->Render(m4Projection, m4View, m4Model);

	translateAmount.x = -6;

	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;
	meshList[39]->Render(m4Projection, m4View, m4Model);

	translateAmount.x = 6;

	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;
	meshList[40]->Render(m4Projection, m4View, m4Model);

	translateAmount.x = 10;

	m4Translate = glm::translate(IDENTITY_M4, translateAmount);

	m4Model = m4Translate;
	meshList[41]->Render(m4Projection, m4View, m4Model);


	//new row 
	translateAmount.y = -6;
	translateAmount.x = -4;
	counter = 2;

	for (int i = 0; i < 4; i++) {
		if (i == counter) {
			translateAmount.x += 2;
		}
		m4Translate = glm::translate(IDENTITY_M4, translateAmount);

		m4Model = m4Translate;
		meshList[42 + i]->Render(m4Projection, m4View, m4Model);
		translateAmount.x += 2;

	}

	//movement += .1;
		
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{

	
	//SafeDelete(m_pMesh1);
	for (int i = 0; i < meshList.size(); i++) {
		MyMesh* del = meshList.at(i);
		delete del;
		del = NULL;
	}
	meshList.clear();

	/*if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}*/
	//release GUI
	ShutdownGUI();
}