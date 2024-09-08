#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <dwmapi.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"
#include "cheats/aimbot/aimbot.hpp"
#include "cheats/visuals/visuals.hpp"
#include "Controller.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")
#ifndef IM_PI
#define IM_PI 3.14159265358979323846f
#endif



IDirect3D9Ex* p_object = NULL;
IDirect3DDevice9Ex* p_device = NULL;
D3DPRESENT_PARAMETERS p_params = { NULL };
MSG messager = { NULL };
HWND my_wnd = NULL;
HWND game_wnd = NULL;

int getFps()
{
	MASK
	using namespace std::chrono;
	static int count = 0;
	static auto last = high_resolution_clock::now();
	auto now = high_resolution_clock::now();
	static int fps = 0;

	count++;

	if (duration_cast<milliseconds>(now - last).count() > 1000)
	{
		fps = count;
		count = 0;
		last = now;
	}

	return fps;
}

HRESULT directx_init()
{
	MASK
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_object))) exit(3);

	ZeroMemory(&p_params, sizeof(p_params));
	p_params.Windowed = TRUE;
	p_params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	p_params.hDeviceWindow = my_wnd;
	p_params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	p_params.BackBufferFormat = D3DFMT_A8R8G8B8;
	p_params.BackBufferWidth = settings::width;
	p_params.BackBufferHeight = settings::height;
	p_params.EnableAutoDepthStencil = TRUE;
	p_params.AutoDepthStencilFormat = D3DFMT_D16;
	p_params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (FAILED(p_object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, my_wnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_params, 0, &p_device)))
	{
		p_object->Release();
		exit(4);
	}

	ImGui::CreateContext();
	ImGui_ImplWin32_Init(my_wnd);
	ImGui_ImplDX9_Init(p_device);

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImFontAtlas* fontAtlas = io.Fonts;
	ImFontConfig arialConfig;
	arialConfig.FontDataOwnedByAtlas = false;
	ImFont* arialFont = fontAtlas->AddFontFromFileTTF("c:\\Windows\\Fonts\\Bahnschrift.ttf", 14.0f, &arialConfig);
	io.Fonts = fontAtlas;
	io.IniFilename = 0;

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	ImVec4 neonGreen = ImVec4(0.00f, 1.00f, 0.20f, 1.00f);
	ImVec4 neonGreenDim = ImVec4(0.00f, 0.80f, 0.15f, 1.00f);
	ImVec4 neonGreenBright = ImVec4(0.40f, 1.00f, 0.50f, 1.00f);

	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);

	colors[ImGuiCol_Text] = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);

	colors[ImGuiCol_Header] = ImVec4(neonGreenDim.x, neonGreenDim.y, neonGreenDim.z, 0.55f);
	colors[ImGuiCol_HeaderHovered] = neonGreenDim;
	colors[ImGuiCol_HeaderActive] = neonGreenBright;

	colors[ImGuiCol_Button] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.60f);
	colors[ImGuiCol_ButtonHovered] = neonGreen;
	colors[ImGuiCol_ButtonActive] = neonGreenBright;

	colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.15f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.67f);

	colors[ImGuiCol_Tab] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.80f);
	colors[ImGuiCol_TabHovered] = neonGreen;
	colors[ImGuiCol_TabActive] = neonGreenBright;
	colors[ImGuiCol_TabUnfocused] = ImVec4(neonGreenDim.x, neonGreenDim.y, neonGreenDim.z, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = neonGreenDim;

	colors[ImGuiCol_TitleBg] = ImVec4(neonGreenDim.x, neonGreenDim.y, neonGreenDim.z, 0.60f);
	colors[ImGuiCol_TitleBgActive] = neonGreen;
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.40f);

	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(neonGreen.x, neonGreen.y, neonGreen.z, 0.80f);
	colors[ImGuiCol_ScrollbarGrabHovered] = neonGreen;
	colors[ImGuiCol_ScrollbarGrabActive] = neonGreenBright;

	colors[ImGuiCol_CheckMark] = neonGreenBright;

	colors[ImGuiCol_SliderGrab] = neonGreen;
	colors[ImGuiCol_SliderGrabActive] = neonGreenBright;

	style.FramePadding = ImVec2(6, 4);
	style.WindowRounding = 3.0f;
	style.ChildRounding = 3.0f;
	style.FrameRounding = 3.0f;
	style.PopupRounding = 3.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabRounding = 1.0f;
	style.TabRounding = 3.0f;
	style.GrabMinSize = 2.0f;

	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_None;

	style.DisplaySafeAreaPadding = ImVec2(8, 8);

	p_object->Release();
	return S_OK;
}

//void create_overlay() // OVERLAY I MAKE THE NEW ONE BUT IS A BIT MORE LAGGY SO WE USE OLD ONE
//{
//	MASK
//	WNDCLASSEXA wcex = {
//		sizeof(WNDCLASSEXA),           
//		0,                             
//		DefWindowProcA,                 
//		0,                            
//		0,                             
//		GetModuleHandleA(nullptr),      
//		LoadIcon(nullptr, IDI_APPLICATION),   
//		LoadCursor(nullptr, IDC_ARROW), 
//		nullptr,                        
//		nullptr,                       
//		"Desi",                       
//		LoadIcon(nullptr, IDI_APPLICATION)    
//	};
//
//	ATOM classAtom = RegisterClassExA(&wcex);
//	if (!classAtom) {
//		MessageBoxA(nullptr, "Failed to register window class!", "Error", MB_ICONERROR | MB_OK);
//		return;
//	}
//
//
//	RECT desktopRect;
//	if (!GetWindowRect(GetDesktopWindow(), &desktopRect)) {
//		MessageBoxA(nullptr, "Failed to get desktop window rect!", "Error", MB_ICONERROR | MB_OK);
//		return;
//	}
//
//	my_wnd = gui::create_window_in_band(
//		0,                          
//		classAtom,                  
//		L"Desi",                    
//		WS_POPUP,                  
//		desktopRect.left,          
//		desktopRect.top,            
//		desktopRect.right - desktopRect.left,  
//		desktopRect.bottom - desktopRect.top,  
//		nullptr,                    
//		nullptr,                    
//		wcex.hInstance,            
//		nullptr,                    
//		gui::ZBID_UIACCESS          
//	);
//
//	if (!my_wnd) {
//		MessageBoxA(nullptr, "Failed to create overlay window!", "Error", MB_ICONERROR | MB_OK);
//		return;
//	}
//
//	
//	SetWindowLong(my_wnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
//
//	
//	SetLayeredWindowAttributes(my_wnd, RGB(0, 0, 0), 255, LWA_ALPHA);
//
//	
//	MARGINS margins = { -1 };
//	if (FAILED(DwmExtendFrameIntoClientArea(my_wnd, &margins))) {
//		MessageBoxA(nullptr, "Failed to extend frame into client area!", "Error", MB_ICONERROR | MB_OK);
//		return;
//	}
//
//	
//	ShowWindow(my_wnd, SW_SHOWDEFAULT);
//	UpdateWindow(my_wnd);
//}


// OLD OVERALY add it back bc is a little bit better fps

void create_overlay()
{
	WNDCLASSEXA wcex = {
		sizeof(WNDCLASSEXA),
		0,
		DefWindowProcA,
		0,
		0,
		0,
		LoadIcon(0, IDI_APPLICATION),
		LoadCursor(0, IDC_ARROW),
		0,
		0,
		"Desi",
		LoadIcon(0, IDI_APPLICATION)
	};
	ATOM rce = RegisterClassExA(&wcex);
	RECT rect;
	GetWindowRect(GetDesktopWindow(), &rect);
	my_wnd = gui::create_window_in_band(0, rce, L"Desi", WS_POPUP, rect.left, rect.top, rect.right, rect.bottom, 0, 0, wcex.hInstance, 0, gui::ZBID_UIACCESS);
	SetWindowLong(my_wnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	RECT desktopRect;
	if (!GetWindowRect(GetDesktopWindow(), &desktopRect)) {
		MessageBoxA(nullptr, "Failed to get desktop window rect!", "Error", MB_ICONERROR | MB_OK);// TEST I MAKING DONT CARE ABOUT THIS
		return;
	}
	SetLayeredWindowAttributes(my_wnd, RGB(0, 0, 0), 255, LWA_ALPHA);
	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(my_wnd, &margin);
	ShowWindow(my_wnd, SW_SHOWDEFAULT);
	UpdateWindow(my_wnd);
}



void features()
{
	MASK
	if (settings::aimbot::enable)
	{
		if (settings::aimbot::mouseAim && settings::aimbot::controller && (GetAsyncKeyState(settings::aimbot::current_key) || Controller::IsPressingLeftTrigger()))
		{
			mouseAim(cache::closest_mesh);
		}

		if (settings::aimbot::mouseAim && !settings::aimbot::controller && GetAsyncKeyState(settings::aimbot::current_key))
		{
			mouseAim(cache::closest_mesh);
		}

		if (settings::aimbot::playerfreeze)	
		{
			if ((GetAsyncKeyState(settings::aimbot::current_key) < 0))
			{
				//if (write<float>(cache::Pawn_Private + 0x68, 0.0f))
				//{
				//
				//}// CustomTimeDilation
			}
			else
			{
				//write<float>(cache::Pawn_Private + 0x68, 1.0f); //CustomTimeDilation;
			}
		}
		if (settings::aimbot::silentAim && GetAsyncKeyState(settings::aimbot::current_key))
		{
			silentAim(cache::closest_mesh);
		}

		if (settings::aimbot::crosshair)
		{
			//ImGui::GetForegroundDrawList()->AddLine(ImVec2(GetSystemMetrics(0) / 2 - 8, GetSystemMetrics(1) / 2), ImVec2(GetSystemMetrics(0) / 2 + 8, GetSystemMetrics(1) / 2), ImColor(0, 0, 0), 2.0f);
			//ImGui::GetForegroundDrawList()->AddLine(ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2 - 8), ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2 + 8), ImColor(0, 0, 0), 2.0f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(GetSystemMetrics(0) / 2 - 8, GetSystemMetrics(1) / 2), ImVec2(GetSystemMetrics(0) / 2 + 8, GetSystemMetrics(1) / 2), settings::colors::icCrosshairColor, 1.0f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2 - 8), ImVec2(GetSystemMetrics(0) / 2, GetSystemMetrics(1) / 2 + 8), settings::colors::icCrosshairColor, 1.0f);
		}

		if (settings::aimbot::show_fovfilled)
		{
			ImVec2 center(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);

			// Circle parameters
			float radius = settings::aimbot::fov;
			int num_segments = 100;

			std::vector<ImColor> colors = {
				ImColor(0, 0, 0, 100),   // Black (100/255 transparency)
			};

			// Calculate number of colors
			int num_colors = colors.size();

			// Get the foreground draw list
			auto draw_list = ImGui::GetForegroundDrawList();

			// Loop through the segments to draw colored triangles
			for (int i = 0; i < num_segments; ++i)
			{
				// Calculate angles for the current segment
				float angle_start = (2.0f * IM_PI * i) / num_segments;
				float angle_end = (2.0f * IM_PI * (i + 1)) / num_segments;

				// Calculate positions of triangle vertices
				ImVec2 start_pos = ImVec2(center.x + radius * cosf(angle_start),
					center.y + radius * sinf(angle_start));
				ImVec2 end_pos = ImVec2(center.x + radius * cosf(angle_end),
					center.y + radius * sinf(angle_end));

				// Determine colors for the current segment
				ImColor start_color = colors[i % num_colors];
				ImColor end_color = colors[(i + 1) % num_colors];

				// Draw the filled triangle segment
				draw_list->AddTriangleFilled(center, start_pos, end_pos, start_color);
				draw_list->AddTriangleFilled(center, start_pos, end_pos, end_color);
			}
		}


		if (settings::aimbot::show_fov)
		{
			ImGui::GetForegroundDrawList()->AddCircle(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), settings::aimbot::fov, settings::colors::icFovColor, 100, 1.0f);
		}

	}

	actorLoop();



	//if (settings::visuals::radar) // OLD ASF RADAR BROKEND
	//{
	//	// Define window flags based on the current state of settings::show_menu
	//	int windowFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
	//		ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
	//	if (!settings::show_menu)
	//	{
	//		windowFlags |= ImGuiWindowFlags_NoMove; // Add NoMove flag if menu is not shown
	//	}

	//	// Set the size of the radar window
	//	ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Always);

	//	// Start a new ImGui window with the specified flags
	//	if (ImGui::Begin("Radar", nullptr, windowFlags))
	//	{
	//		ImVec2 windowPos = ImGui::GetWindowPos();
	//		ImVec2 windowSize = ImGui::GetWindowSize();
	//		ImDrawList* drawList = ImGui::GetWindowDrawList();

	//		// Calculate center of the radar
	//		ImVec2 center(windowPos.x + windowSize.x * 0.5f, windowPos.y + windowSize.y * 0.5f);

	//		// Draw radar background lines
	//		drawList->AddLine(ImVec2(center.x, windowPos.y), ImVec2(center.x, windowPos.y + windowSize.y), ImColor(25, 25, 25), 1.0f);
	//		drawList->AddLine(ImVec2(windowPos.x, center.y), ImVec2(windowPos.x + windowSize.x, center.y), ImColor(25, 25, 25), 1.0f);
	//		drawList->AddLine(center, ImVec2(windowPos.x, windowPos.y), ImColor(25, 25, 25), 1.0f);
	//		drawList->AddLine(center, ImVec2(windowPos.x + windowSize.x, windowPos.y), ImColor(25, 25, 25), 1.0f);

	//		// Draw the center point
	//		drawList->AddCircleFilled(center, 5.0f, ImColor(255, 255, 255));

	//		// Draw radar points from cache
	//		for (const ImVec2& radarPos : cache::radarPoints)
	//		{
	//			ImVec2 pointPosition(windowPos.x + radarPos.x, windowPos.y + radarPos.y);
	//			drawList->AddCircleFilled(pointPosition, 5.0f, ImColor(255, 0, 0));
	//		}

	//		ImGui::End();
	//	}
	//}
}

void render_menu()
{
	MASK
	switch (settings::aimbot::current_aimkey)
	{
	case 0:
		settings::aimbot::current_key = VK_LBUTTON;
		break;
	case 1:
		settings::aimbot::current_key = VK_RBUTTON;
		break;
	case 2:
		settings::aimbot::current_key = VK_XBUTTON1;
		break;
	case 3:
		settings::aimbot::current_key = VK_XBUTTON2;
		break;
	case 4:
		settings::aimbot::current_key = VK_SHIFT;
		break;
	case 5:
		settings::aimbot::current_key = VK_CONTROL;
		break;
	case 6:
		settings::aimbot::current_key = VK_MENU;
		break;
	case 7:
		settings::aimbot::current_key = VK_CAPITAL;
		break;
	default:
		settings::aimbot::current_key = VK_LBUTTON; // default to left mouse button
		break;
	}

	char watermarkText[64];
	sprintf_s(watermarkText, "Payson Slotted\n%.i FPS", getFps());
	ImVec2 wmTextSize = ImGui::CalcTextSize(watermarkText);
	ImVec2 rectSize = ImVec2(wmTextSize.x + 2 * 10.0f, wmTextSize.y + 2 * 5.0f);
	ImVec2 rectPos = ImVec2(5, 5);
	//ImGui::GetForegroundDrawList()->AddRectFilled(rectPos, ImVec2(rectPos.x + rectSize.x, rectPos.y + rectSize.y), ImColor(10, 10, 10), 0, 0);
	//ImGui::GetForegroundDrawList()->AddRectFilled(rectPos, ImVec2(rectPos.x + rectSize.x, rectPos.y + 2), ImColor(255, 0, 255), 0, 0);
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetFont(), 14.0f, ImVec2(rectPos.x + (rectSize.x - wmTextSize.x) / 2, rectPos.y + (rectSize.y - wmTextSize.y) / 2), ImColor(255, 0, 255), watermarkText);

	if (GetAsyncKeyState(VK_INSERT) & 1) settings::show_menu = !settings::show_menu;
	if (settings::show_menu)
	{
		static int counter = 0;
		const char* tabs[] = { "Aimbot", "Visuals", "Exploits" };
		static int current_tab = 0;
		float availableWidth = ImGui::GetContentRegionAvail().x;

		float width = ImGui::GetColumnWidth() - 10.0f - ImGui::GetStyle().ChildBorderSize * 2;

		ImGui::SetNextWindowSize({ 650, 450 });
		ImGui::Begin("Payson Slotted - github.com/paysonism", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
		{
			// Calculate available width for content
			float availableWidth = ImGui::GetContentRegionAvail().x;

			// Calculate width for each column (subtracting space for padding)
			float columnWidth = (availableWidth - ImGui::GetStyle().ItemSpacing.x) / 2.0f;

			ImGui::NeonTabs("##VerticalTabs", tabs, IM_ARRAYSIZE(tabs), &current_tab);

			ImGui::SameLine();
			ImGui::BeginGroup();
			switch (current_tab)
			{
			case 0:
				ImGui::Columns(2, nullptr, true);
				ImGui::SetColumnWidth(0, columnWidth);
				ImGui::SetColumnWidth(1, columnWidth);

					ImGui::Text("Aimbot Toggles");
					ImGui::Dummy(ImVec2(0, 1.0f));

					ImGui::CustomCheckbox("Enable Aimbot", &settings::aimbot::enable);
					if (settings::aimbot::enable)
					{
						ImGui::CustomCheckbox("Kernel Aim", &settings::aimbot::mouseAim);
						ImGui::CustomCheckbox("Silent Aim", &settings::aimbot::silentAim);
						ImGui::CustomCheckbox("XBOX Controller Support", &settings::aimbot::controller);
						ImGui::CustomCheckbox("Prediction", &settings::aimbot::bulletPrediction);
						ImGui::CustomCheckbox("Crosshair", &settings::aimbot::crosshair);
						ImGui::CustomCheckbox("Show FOV", &settings::aimbot::show_fov);
						ImGui::CustomCheckbox("Filled FOV", &settings::aimbot::show_fovfilled);
					}
				
				ImGui::NextColumn();
				
					ImGui::Text("Aimbot Settings");
					ImGui::Dummy(ImVec2(0, 1.0f));

					ImGui::SliderFloatNeon("FOV", &settings::aimbot::fov, 50, 600, "%.f");
					ImGui::SliderFloatNeon("Smoothness", &settings::aimbot::smoothness, 1, 25, "%.f%");
					ImGui::Combo("AimKey", &settings::aimbot::current_aimkey, settings::aimbot::aimkey, sizeof(settings::aimbot::aimkey) / sizeof(*settings::aimbot::aimkey));
					if (ImGui::BeginCombo("Hitbox", getHitboxTypeName(settings::aimbot::current_hitbox)))
					{
						for (auto hitboxType : hitboxValues)
						{
							if (ImGui::Selectable(getHitboxTypeName(hitboxType), settings::aimbot::current_hitbox == hitboxType)) settings::aimbot::current_hitbox = hitboxType;
						}
						ImGui::EndCombo();
					}

				ImGui::Columns(1);
				break;
			case 1:
				ImGui::Columns(2, nullptr, false);
				ImGui::SetColumnWidth(0, columnWidth);
				ImGui::SetColumnWidth(1, columnWidth);

					ImGui::Text("Visuals Toggles");
					ImGui::Dummy(ImVec2(0, 1.0f));

					ImGui::CustomCheckbox("Enable Visuals", &settings::visuals::enable);
					if (settings::visuals::enable)
					{
						ImGui::CustomCheckbox("Box", &settings::visuals::box);
						ImGui::CustomCheckbox("Radar", &settings::visuals::niggasud);
						ImGui::CustomCheckbox("Weapon", &settings::visuals::weapon);
						ImGui::CustomCheckbox("Skeleton", &settings::visuals::skeleton);
						ImGui::CustomCheckbox("Line", &settings::visuals::line);
						ImGui::CustomCheckbox("Platform", &settings::visuals::platform);
						ImGui::CustomCheckbox("Name", &settings::visuals::name);
						ImGui::CustomCheckbox("Distance", &settings::visuals::distance);
						ImGui::CustomCheckbox("Rank", &settings::visuals::rank);
					}

				ImGui::NextColumn();

					ImGui::Text("Visuals Settings");
					ImGui::Separator();
					ImGui::Dummy(ImVec2(0, 1.0f));

					ImGui::SliderFloatNeon("Render Distance", &settings::visuals::renderDistance, 100, 3000, "%.fm");
					if (ImGui::BeginCombo("Box Type", getBoxTypeName(settings::visuals::boxType)))
					{
						for (auto boxType : boxValues)
						{
							if (ImGui::Selectable(getBoxTypeName(boxType), settings::visuals::boxType == boxType)) settings::visuals::boxType = boxType;
						}
						ImGui::EndCombo();
					}

				ImGui::Columns(1);
				break;
			case 2:
				ImGui::Columns(2, nullptr, true);
				ImGui::SetColumnWidth(0, columnWidth);
				ImGui::SetColumnWidth(1, columnWidth);

				ImGui::Text("Crosshair Color");
				ImGui::ColorEdit3("##crosshair", reinterpret_cast<float*>(&settings::colors::icCrosshairColor));
				ImGui::CustomCheckbox("Spinbot", &settings::exploits::spinbot);
				ImGui::CustomCheckbox("Doublepump", &settings::exploits::doublepump);
				ImGui::CustomCheckbox("Airstuck", &settings::exploits::AirStuck);
				ImGui::CustomCheckbox("Player Fly", &settings::exploits::creative_fly);
				ImGui::CustomCheckbox("No Recoil", &settings::exploits::norecoil);
				ImGui::CustomCheckbox("Magic Bullet (No Player Damage)", &settings::exploits::magicbullet);
				ImGui::CustomCheckbox("No Reload", &settings::exploits::noreload);
				ImGui::CustomCheckbox("Auto Run", &settings::exploits::autorun);
				ImGui::CustomCheckbox("Instant Revive", &settings::exploits::instantrevive);
				ImGui::CustomCheckbox("NoEquipAnimation", &settings::exploits::NoEquipAnimation);
				ImGui::CustomCheckbox("Instant Reboot", &settings::exploits::instaReboot);

				ImGui::NextColumn();

				ImGui::CustomCheckbox("Vehicle No Cooldown", &settings::exploits::vehicle_nocooldodwn);
				ImGui::CustomCheckbox("No Weapon Cooldown (CRASH)", &settings::exploits::bNoWeaponCooldown);
				ImGui::CustomCheckbox("FOV Changer", &settings::exploits::fovchanger);
				ImGui::SliderFloatNeon("FOV Changer Value", &settings::exploits::fovchanger_value, 95, 130);
				ImGui::CustomCheckbox("Aim While Jumping", &settings::exploits::aimwhilejumping);
				ImGui::CustomCheckbox("No Overheat", &settings::exploits::overheat);
				ImGui::CustomCheckbox("CarFly", &settings::exploits::carfly);
				ImGui::CustomCheckbox("bFullAutoWeapons", &settings::exploits::bFullAutoWeapons);
				ImGui::CustomCheckbox("bRapidFire", &settings::exploits::bRapidFire);
				ImGui::CustomCheckbox("Vehicle Spinbot", &settings::exploits::bVehicleTestAttributesTwo);
				ImGui::CustomCheckbox("bClientLocMod", &settings::exploits::bClientLocMod);
				ImGui::CustomCheckbox("FirstPerson", &settings::exploits::FirstPerson);
				ImGui::CustomCheckbox("Freeze Players", &settings::aimbot::playerfreeze);
				ImGui::Columns(1);

				ImGui::Columns(1);
				break;
			}
			ImGui::EndGroup();
		}
		ImGui::End();
	}
}

HWND get_process_wnd(uint32_t pid)
{
	std::pair<HWND, uint32_t> params = { 0, pid };
	BOOL bresult = EnumWindows([](HWND hwnd, LPARAM lparam) -> BOOL
		{
			auto pparams = (std::pair<HWND, uint32_t>*)(lparam);
			uint32_t processid = 0;
			if (GetWindowThreadProcessId(hwnd, reinterpret_cast<LPDWORD>(&processid)) && processid == pparams->second)
			{
				SetLastError((uint32_t)-1);
				pparams->first = hwnd;
				return FALSE;
			}
			return TRUE;
		}, (LPARAM)&params);

	if (!bresult && GetLastError() == -1 && params.first) return params.first;

	return 0;
}

WPARAM render_loop()
{
	static RECT old_rc;

	bool running = true;
	while (running)
	{
		while (PeekMessage(&messager, my_wnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&messager);
			DispatchMessage(&messager);
			if (messager.message == WM_QUIT)
			{
				running = false;
			}
		}

		if (!running) break;

		if (game_wnd == NULL) exit(0);

		HWND active_wnd = GetForegroundWindow();
		if (active_wnd == game_wnd)
		{
			HWND target_wnd = GetWindow(active_wnd, GW_HWNDPREV);
			SetWindowPos(my_wnd, target_wnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		else
		{
			game_wnd = get_process_wnd(mem::process_id);
			Sleep(250);
		}

		RECT rc;
		POINT xy;
		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		rc.left = xy.x;
		rc.top = xy.y;
		ImGuiIO& io = ImGui::GetIO();
		io.DeltaTime = 1.0f / 60.0f;
		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(0x1))
		{
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
		{
			io.MouseDown[0] = false;
		}

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;
			settings::width = rc.right;
			settings::height = rc.bottom;
			p_params.BackBufferWidth = settings::width;
			p_params.BackBufferHeight = settings::height;
			SetWindowPos(my_wnd, (HWND)0, xy.x, xy.y, settings::width, settings::height, SWP_NOREDRAW);
			p_device->Reset(&p_params);
		}

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			features();
			render_menu();
		}
		ImGui::EndFrame();
		ImGui::Render();

		p_device->SetRenderState(D3DRS_ZENABLE, false);
		p_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		p_device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		p_device->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

		if (p_device->BeginScene() >= 0)
		{
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			p_device->EndScene();
		}

		HRESULT result = p_device->Present(0, 0, 0, 0);
		if (result == D3DERR_DEVICELOST && p_device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			p_device->Reset(&p_params);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (p_device != 0)
	{
		p_device->EndScene();
		p_device->Release();
	}

	if (p_object != 0) p_object->Release();

	DestroyWindow(my_wnd);

	return messager.wParam;
}
