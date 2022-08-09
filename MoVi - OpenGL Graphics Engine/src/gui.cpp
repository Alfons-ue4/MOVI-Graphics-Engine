#include "gui.h"


void MVGui::init(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_DockingEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void MVGui::exit()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void MVGui::render()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void MVGui::createWindows()
{
	createDebugWindow();
	createStatWindow();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool MVGui::wantMouse()
{
	return ImGui::GetIO().WantCaptureMouse;
}

void MVGui::createDebugWindow()
{
	ImGui::Begin("Options");

	ImGui::Text("Scene settings:");
	ImGui::ColorEdit3("Background Color", bgColor);
	ImGui::NewLine();

	ImGui::Text("Camera settings:");
	ImGui::SliderFloat("Camera Speed", &cameraSpeed, 1.0f, 10.0f);
	ImGui::SliderFloat("Camera Sensitivity", &sensitivity, 1.0f, 100.0f);
	ImGui::SliderFloat("Camera Field of view", &cameraFov, 10.0f, 120.0f);
	ImGui::End();
}

void MVGui::createStatWindow()
{
	ImGui::Begin("Performance", (bool*)false, 
	ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | 
	ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | 
	ImGuiWindowFlags_NoTitleBar);

	mFps = "fps: " + std::to_string(ImGui::GetIO().Framerate);
	ImGui::Text(mFps.c_str());

	ImGui::End();
}
