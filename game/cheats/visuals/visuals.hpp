#pragma once
#include "../../../includes.hpp"
#include <iostream>               // For std::cout
#include <string>                 // For std::string
#include <unordered_map>          // For std::unordered_map]
ImFont* m_pFont;
ImFont* esp_pFont;

void stroked_text(ImFont* font, float fontSize, ImVec2 position, ImColor color, const char* text)
{
	MASK
	ImGui::GetForegroundDrawList()->AddText(font, fontSize, ImVec2(position.x - 1, position.y - 1), ImColor(0, 0, 0), text);
	ImGui::GetForegroundDrawList()->AddText(font, fontSize, ImVec2(position.x + 1, position.y - 1), ImColor(0, 0, 0), text);
	ImGui::GetForegroundDrawList()->AddText(font, fontSize, ImVec2(position.x - 1, position.y + 1), ImColor(0, 0, 0), text);
	ImGui::GetForegroundDrawList()->AddText(font, fontSize, ImVec2(position.x + 1, position.y + 1), ImColor(0, 0, 0), text);
	ImGui::GetForegroundDrawList()->AddText(font, fontSize, position, color, text);
}

void draw_filledbox(int x, int y, int w, int h, const ImColor& fillColor, const ImColor& outlineColor) {
	// Draw filled rectangle (main body of the box)
	ImGui::GetForegroundDrawList()->AddRectFilled(
		ImVec2(x, y), ImVec2(x + w, y + h), fillColor, 0, 0
	);

	// Draw outline (border)
	ImGui::GetForegroundDrawList()->AddRect(
		ImVec2(x, y), ImVec2(x + w, y + h), outlineColor, 0, 0, 2.0f
	);
}

void draw_box(int x, int y, int w, int h, const ImColor color)
{
	MASK
	//ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(0, 0, 0, 50), 0, 0);
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x + 1, y + 1), ImVec2(x + w - 1, y + h - 1), ImColor(0, 0, 0), 0, 0, 1.0f);
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x - 1, y - 1), ImVec2(x + w + 1, y + h + 1), ImColor(0, 0, 0), 0, 0, 1.0f);
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x + 1, y - 1), ImVec2(x + w - 1, y + h + 1), ImColor(0, 0, 0), 0, 0, 1.0f);
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x - 1, y + 1), ImVec2(x + w + 1, y + h - 1), ImColor(0, 0, 0), 0, 0, 1.0f);
	ImGui::GetForegroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0, 1.0f);
}

static void draw_corner_box(float x, float y, float w, float h, ImColor color)
{
	MASK
	//ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImColor(0, 0, 0, 100), 0, 0);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x - 1, y - 1), ImVec2(x - 1, y + (h / 3) - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x - 1, y - 1), ImVec2(x + (w / 3) - 1, y - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3) + 1, y - 1), ImVec2(x + w + 1, y - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w + 1, y - 1), ImVec2(x + w + 1, y + (h / 3) - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x - 1, y + h - (h / 3) + 1), ImVec2(x - 1, y + h + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x - 1, y + h + 1), ImVec2(x + (w / 3) - 1, y + h + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3) + 1, y + h + 1), ImVec2(x + w + 1, y + h + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w + 1, y + h - (h / 3) + 1), ImVec2(x + w + 1, y + h + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + 1, y + 1), ImVec2(x + 1, y + (h / 3) + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + 1, y + 1), ImVec2(x + (w / 3) + 1, y + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3) - 1, y + 1), ImVec2(x + w - 1, y + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - 1, y + 1), ImVec2(x + w - 1, y + (h / 3) + 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + 1, y + h - (h / 3) - 1), ImVec2(x + 1, y + h - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + 1, y + h - 1), ImVec2(x + (w / 3) + 1, y + h - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3) - 1, y + h - 1), ImVec2(x + w - 1, y + h - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - 1, y + h - (h / 3) - 1), ImVec2(x + w - 1, y + h - 1), ImColor(0, 0, 0), 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x, y), ImVec2(x, y + (h / 3)), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x, y), ImVec2(x + (w / 3), y), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3), y), ImVec2(x + w, y), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w, y), ImVec2(x + w, y + (h / 3)), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x, y + h - (h / 3)), ImVec2(x, y + h), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x, y + h), ImVec2(x + (w / 3), y + h), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w - (w / 3), y + h), ImVec2(x + w, y + h), color, 1.0f);
	ImGui::GetForegroundDrawList()->AddLine(ImVec2(x + w, y + h - (h / 3)), ImVec2(x + w, y + h), color, 1.0f);
}

struct Fortnite
{
	// Enum to represent different actor types in the game
	enum ActorType
	{
		NOT_IN_USE = 0,
		CHEST = 1,
		AMMO_BOX = 2,
	};

	// Struct to define actor properties
	struct ActorDefinitions
	{
		int actorID;           // Actor ID
		std::string fname;     // Actor name
		ActorType actorType;   // Actor type
	};

	// Static method to return a map of actor names to actor types
	static const std::unordered_map<std::string, ActorType>& GetActorByName()
	{
		// Static map to store the association between actor names and their types
		static const std::unordered_map<std::string, ActorType> actorMap = {
			{"Tiered_Chest", CHEST},
			{"Tiered_Ammo", AMMO_BOX},
			// Add more actors as needed
		};

		return actorMap;
	}
};
void GetActorLocations()
{
	auto levels = read<TArray<uintptr_t>>(GWORLD + FNLevels); // IM FUCKING DONE BRO NO LOOT ESP IDC
	if (!levels.is_valid())
		return;

	//for (size_t i = 0; i < levels.length(); ++i) {
	//	uintptr_t levelAddress = levels[i];
}

void actorLoop()
{
	MASK
		__int64 va_text = 0;
	for (int i = 0; i < 25; i++)
	{
		if (read<__int32>(virtualaddy + (i * 0x1000) + 0x250) == 0x6F41C00)
		{
			va_text = virtualaddy + ((i + 1) * 0x1000);
		}
	}
	cache::gworld = read<uintptr_t>(GWORLD + va_text);
	if (!cache::gworld) return;

	cache::game_instance = read<uintptr_t>(cache::gworld + GAME_INSTANCE);
	if (!cache::game_instance) return;

	cache::local_players = read<uintptr_t>(read<uintptr_t>(cache::game_instance + LOCAL_PLAYERS));
	if (!cache::local_players) return;

	cache::player_controller = read<uintptr_t>(cache::local_players + PLAYER_CONTROLLER);
	if (!cache::player_controller) return;

	cache::game_state = read<uintptr_t>(cache::gworld + GAME_STATE);
	if (!cache::game_state) return;

	cache::local_pawn = read<uintptr_t>(cache::player_controller + LOCAL_PAWN);
	if (!cache::local_pawn) return;

	cache::persistent_level = read<uintptr_t>(cache::gworld + PERSISTENT_LEVEL);
	if (!cache::persistent_level) return;

	cache::root_component = read<uintptr_t>(cache::local_pawn + ROOT_COMPONENT);
	if (!cache::root_component) return;

	cache::player_state = read<uintptr_t>(cache::local_pawn + PLAYER_STATE);
	if (!cache::player_state) return;

	cache::current_weapon = read<uintptr_t>(cache::local_pawn + CURRENT_WEAPON);
	if (!cache::current_weapon) return;

	cache::localRelativeLocation = read<Vector3>(cache::root_component + RELATIVE_LOCATION);
	cache::closest_distance = FLT_MAX;
	cache::closest_mesh = NULL;

	uintptr_t game_state = read<uintptr_t>(cache::gworld + GAME_STATE);
	if (!game_state) return;

	uintptr_t player_array = read<uintptr_t>(game_state + PLAYER_ARRAY);
	uintptr_t player_count = read<int>(game_state + (PLAYER_ARRAY + sizeof(uintptr_t)));

	for (int i = 0; i < player_count; i++)
	{
			uintptr_t player_state = read<uintptr_t>(player_array + (i * sizeof(uintptr_t)));
			if (!player_state) continue;

			uintptr_t pawn_private = read<uintptr_t>(player_state + PAWN_PRIVATE);
			if (!pawn_private) continue;
			if (pawn_private == cache::local_pawn) continue;

			uintptr_t mesh = read<uintptr_t>(pawn_private + MESH);
			if (!mesh) continue;

			uintptr_t actorRootComponent = read<uintptr_t>(pawn_private + ROOT_COMPONENT);
			Vector3 actorRelativeLocation = read<Vector3>(actorRootComponent + RELATIVE_LOCATION);
			float distance = cache::localRelativeLocation.distance(actorRelativeLocation) / 100.0f;

			Vector3 head3d = get_entity_bone(mesh, 110);
			Vector2 head2d = project_world_to_screen(head3d);
			Vector3 bottom3d = get_entity_bone(mesh, 0);
			Vector2 bottom2d = project_world_to_screen(bottom3d);
			Vector2 Bottom2D = project_world_to_screen(bottom3d);
			Vector2 boxHead = project_world_to_screen(Vector3(head3d.x, head3d.y, head3d.z + 20.0f));
			float box_height = abs(boxHead.y - bottom2d.y);
			float box_width = box_height * 0.50f;

			if (!cache::local_pawn)
			{
				settings::visuals::distance = 2400;
			}
			if (settings::visuals::enable)
			{
				if (settings::visuals::niggasud)
				{
					add_to_radar(Bottom2D, 187, is_visible);
				}
				if (settings::visuals::niggasud)
				{
					render_radar_main();
				}

				float yOffset = 10.0f; // fix for yOffset dont ask how this work (bc i dont ever know why work xd)
				if (settings::visuals::weapon) // i self code this and work what a sigma andreu is 1337 
				{
					std::string weaponName = get_weapon_name(pawn_private);

					ImVec2 textSize = ImGui::CalcTextSize(weaponName.c_str());
					stroked_text(ImGui::GetFont(), 13.0f, ImVec2(bottom2d.x - textSize.x / 2, bottom2d.y + yOffset - textSize.y / 2), ImColor(255, 255, 255), weaponName.c_str());
				}
				ImColor visibleColor = ImColor(144, 238, 144, 128);   // Light green with 50% transparency
				ImColor invisibleColor = ImColor(34, 139, 34, 128);   // Darker green for invisible
				if (distance <= settings::visuals::renderDistance)
				{
					if (settings::visuals::box)
					{
						switch (settings::visuals::boxType)
						{
						case boxType::normal:
						{
							if (is_visible(mesh))
							{
								draw_box(boxHead.x - (box_width / 2), boxHead.y, box_width, box_height, visibleColor);
							}
							else
							{
								draw_box(boxHead.x - (box_width / 2), boxHead.y, box_width, box_height, invisibleColor);
							}
							break;
						}
						case boxType::corner:
						{
							if (is_visible(mesh))
							{
								draw_corner_box(boxHead.x - (box_width / 2), boxHead.y, box_width, box_height, visibleColor);
							}
							else
							{
								draw_corner_box(boxHead.x - (box_width / 2), boxHead.y, box_width, box_height, invisibleColor);
							}
							break;
						}
						case boxType::filled:
						{
							if (is_visible(mesh)) {
								void draw_filledbox(float x, float y, float width, float height, ImColor color);
							}
							else {
								//	draw_filledbox(boxHead.x - (box_width / 2), boxHead.y, box_width, box_height, visibleColor, additionalParam);
							}
							break;
						}
						}
					}

					if (settings::visuals::skeleton)
					{
						for (int i = 0; i < sizeof(boneConnections) / sizeof(boneConnections[0]); i++)
						{
							int bone1 = boneConnections[i].bone1;
							int bone2 = boneConnections[i].bone2;
							Vector3 vectorBone1 = get_entity_bone(mesh, bone1);
							Vector3 vectorBone2 = get_entity_bone(mesh, bone2);
							Vector2 wtsBone1 = project_world_to_screen(vectorBone1);
							Vector2 wtsBone2 = project_world_to_screen(vectorBone2);

							if (is_visible(mesh))
							{
								ImGui::GetForegroundDrawList()->AddLine(ImVec2(wtsBone1.x, wtsBone1.y), ImVec2(wtsBone2.x, wtsBone2.y), ImColor(0, 0, 0), 2.0f);
								ImGui::GetForegroundDrawList()->AddLine(ImVec2(wtsBone1.x, wtsBone1.y), ImVec2(wtsBone2.x, wtsBone2.y), settings::colors::icSkeletonColorVisible, 1);
							}
							else
							{
								ImGui::GetForegroundDrawList()->AddLine(ImVec2(wtsBone1.x, wtsBone1.y), ImVec2(wtsBone2.x, wtsBone2.y), ImColor(0, 0, 0), 2.0f);
								ImGui::GetForegroundDrawList()->AddLine(ImVec2(wtsBone1.x, wtsBone1.y), ImVec2(wtsBone2.x, wtsBone2.y), settings::colors::icSkeletonColorInvisible, 1);
							}
						}
					}

					if (settings::visuals::line)
					{
						if (is_visible(mesh))
						{
							ImGui::GetForegroundDrawList()->AddLine(ImVec2(settings::screen_center_x, settings::height), ImVec2(bottom2d.x, bottom2d.y), settings::colors::icTracerColorVisible, 1.0f);
						}
						else
						{
							ImGui::GetForegroundDrawList()->AddLine(ImVec2(settings::screen_center_x, settings::height), ImVec2(bottom2d.x, bottom2d.y), settings::colors::icTracerColorInvisible, 1.0f);
						}
					}

					// usage
					float yOffset = 10.0f; // fix for yOffset dont ask how this work (bc i dont ever know why work xd)
					if (settings::visuals::weapon)
					{
						std::string weaponName = get_weapon_name(pawn_private);

						ImVec2 textSize = ImGui::CalcTextSize(weaponName.c_str());
						stroked_text(ImGui::GetFont(), 13.0f, ImVec2(bottom2d.x - textSize.x / 2, bottom2d.y + yOffset - textSize.y / 2), ImColor(255, 255, 255), weaponName.c_str());
					}

					if (settings::visuals::name)
					{
						std::string playerUsername = getUsername(player_state);

						ImVec2 textSize = ImGui::CalcTextSize(playerUsername.c_str());
						stroked_text(ImGui::GetFont(), 13.0f, ImVec2(boxHead.x - textSize.x / 2, boxHead.y - 10 - textSize.y / 2), ImColor(255, 255, 255), playerUsername.c_str());
					}

					if (settings::visuals::platform)
					{
						uintptr_t platformPtr = read<uintptr_t>(player_state + PLATFORM);
						wchar_t platformChar[64] = { 0 };
						//PaysonDRV::ReadPhysical(reinterpret_cast<PVOID>(platformPtr), reinterpret_cast<uint8_t*>(platformChar), sizeof(platformChar));
						std::wstring platformWstr(platformChar);
						std::string platformStr(platformWstr.begin(), platformWstr.end());

						ImVec2 textSize = ImGui::CalcTextSize(platformStr.c_str());
						if (settings::visuals::name)
						{
							stroked_text(ImGui::GetFont(), 13.0f, ImVec2(boxHead.x - textSize.x / 2, boxHead.y - 25 - textSize.y / 2), ImColor(255, 255, 255), platformStr.c_str());
						}
						else
						{
							stroked_text(ImGui::GetFont(), 13.0f, ImVec2(boxHead.x - textSize.x / 2, boxHead.y - 10 - textSize.y / 2), ImColor(255, 255, 255), platformStr.c_str());
						}
					}

					if (settings::visuals::distance)
					{
						char dist[64];
						sprintf_s(dist, "%.fm", distance);

						ImVec2 textSize = ImGui::CalcTextSize(dist);
						stroked_text(ImGui::GetFont(), 13.0f, ImVec2(bottom2d.x - textSize.x / 2, bottom2d.y + 10 - textSize.y / 2), ImColor(255, 255, 255), dist);
					}

					if (settings::visuals::rank)
					{
						uintptr_t habaneroComponent = read<uintptr_t>(player_state + HABANERO_COMPONENT);
						uint32_t rank = read<uint32_t>(habaneroComponent + RANKED_PROGRESS + 0x10);
						std::string rankName = getRank(rank);

						ImVec2 textSize = ImGui::CalcTextSize(rankName.c_str());
						if (settings::visuals::distance)
						{
							stroked_text(ImGui::GetFont(), 13.0f, ImVec2(bottom2d.x - textSize.x / 2, bottom2d.y + 25 - textSize.y / 2), ImColor(255, 255, 255), rankName.c_str());
						}
						else
						{
							stroked_text(ImGui::GetFont(), 13.0f, ImVec2(bottom2d.x - textSize.x / 2, bottom2d.y + 10 - textSize.y / 2), ImColor(255, 255, 255), rankName.c_str());
						}
					}
				}
			}


			bool fovreset;
			bool magicreset;

			if (settings::exploits::noreload)
			{
				////printf("no reload\r\n");

				if (cache::local_pawn && cache::current_weapon)
				{

					//printf("player and weapon - for no reload\r\n");
					uintptr_t mesh = read<uintptr_t>(cache::local_pawn + 0x318); // mesh
					if (mesh)
					{
						//printf("we got mesh!\r\n");
					}
					bool bIsReloading = read<bool>(cache::current_weapon + 0x399); // https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=AFortWeapon&member=bIsReloadingWeapon

					//printf("bIsReloading: %d!\r\n", bIsReloading);

					if (mesh)
					{
						//printf("mesh");

						if (bIsReloading) // bIsReloading
						{
							//printf("fsat forwarding\r\n");

							write<float>(mesh + 0xa28, 999.f); // globalanimratescale
						}
						else
						{
							write<float>(mesh + 0xa28, 1.f);  // globalanimratescale

						}
					}
					else
					{
						//printf("no mesh");
					}
				}
			}


			if (settings::exploits::playerFly)
			{
				write<float>(cache::local_pawn + ZiplineSpeedFactor, 1000); // ZiplineSpeedFactor Updated 29.02.24    
				write<bool>(cache::local_pawn + ZiplineState + 0x18, true); // ZiplineState 
			} //and a zipline fly
			float Playersize = 3.0f; // Set the player size as desired
			if (settings::exploits::tinyplayers)
			{
				auto Mesh = read<uint64_t>(cache::local_pawn + MESH);
				write<Vector3>(Mesh + 0x158, Vector3(Playersize, Playersize, Playersize));
				write<Vector3>(Mesh + 0x158, Vector3(Playersize, Playersize, Playersize));
				write<Vector3>(Mesh + 0x158, Vector3(Playersize, Playersize, Playersize));
			}


			if (settings::exploits::fovchanger)
			{
				MASK
					fovreset = false;
				write<float>(cache::player_controller + 0x2738, settings::exploits::fovchanger_value); // https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=AFortPlayerController&member=FOVMinimum
				write<float>(cache::player_controller + 0x273C, settings::exploits::fovchanger_value); // FOVMaximum
			}
			else if (!fovreset)
			{
				MASK
					write<float>(cache::player_controller + 0x2738, settings::exploits::fovchanger_value); // FOVMinimum
				write<float>(cache::player_controller + 0x273C, settings::exploits::fovchanger_value); // FOVMaximum
				fovreset = true;
			}

			if (settings::exploits::bClientLocMod)
			{
				if (cache::local_pawn && cache::root_component)
				{
					Vector3 previousLoc = read<Vector3>(cache::root_component + 0x120); // RelativeLocation
					Vector3 locationHolder = previousLoc;
					previousLoc.z += 100;
					previousLoc.y += 100;
					write<Vector3>(cache::root_component + 0x120, locationHolder); // RelativeLocation
				}
			}

			if (settings::exploits::norecoil)
			{
				write<float>(cache::player_controller + 0x68, -1);
			}

			if (settings::exploits::magicbullet)
			{
				MASK
					magicreset = false;
				auto weapon = read<uintptr_t>(cache::local_pawn + 0xA68);

				write<bool>(weapon + 0xe51, true);  // 0xe51 or 0x3f8  bTraceThroughWorld
				write<int32_t>(weapon + 0xea8, 0);  // TraceThroughPawnsLimit

				write<int32_t>(weapon + 0xeac, 1000);  // TraceThroughBuildingsLimit
				write<int32_t>(weapon + 0xeb0, 1000);  // TraceThroughLandscapeLimit
			}
			else if (!magicreset)
			{
				MASK
					auto weapon = read<uintptr_t>(cache::local_pawn + 0xA68);

				write<bool>(weapon + 0xe51, false); // bTraceThroughWorld
				write<int32_t>(weapon + 0xea8, 0);  // TraceThroughPawnsLimit
				write<int32_t>(weapon + 0xeac, 0);  // TraceThroughBuildingsLimit
				write<int32_t>(weapon + 0xeb0, 0);  // TraceThroughLandscapeLimit
				magicreset = true;
			}


			if (settings::exploits::bVehicleTestAttributesTwo) // vehicle spinboat test
			{
				if (cache::local_pawn)
				{
					if (uintptr_t CurrentVehicle = read<uintptr_t>(cache::local_pawn + 0x2a18)) // current vehicle offset
					{
						if (uintptr_t VehicleRootComponent = read<uintptr_t>(CurrentVehicle + 0x198))
						{
							if (iVehicleSpin >= 359) {
								iVehicleSpin = 0;
							}

							iVehicleSpin += 5;

							write<Vector3>(VehicleRootComponent + 0x138, Vector3(77, iVehicleSpin, 45)); // RelativeRotation
						}
					}
				}
			}

			if (settings::exploits::bTPose)
			{
				if (cache::closest_mesh)
				{
					write<bool>(cache::closest_mesh + 0xa41, true); // bforcerefpose
					write<bool>(cache::closest_mesh + 0xa41, true); // boldforcerefpose
				}
			}

			if (settings::exploits::bNoWeaponCooldown)
			{
				//printf("cooldown!\r\n");
				if (cache::local_pawn)
				{
					write<float>(cache::local_pawn + 0x1004, 0.00000001f); // EmoteToFireCooldownTime
				}
				if (cache::local_pawn + CURRENT_WEAPON)
				{
					//printf("cdown weapon!\r\n");
					write<float>(cache::local_pawn + CURRENT_WEAPON + 0x68, FLT_MAX); // customtimedilation
					write<float>(cache::local_pawn + CURRENT_WEAPON + 0xf00, 0.f); // ChargeTime
					write<bool>(cache::local_pawn + CURRENT_WEAPON + 0x39a, true); // bDisableEquipAnimation
					write<bool>(cache::local_pawn + CURRENT_WEAPON + 0x39a, true); // bDisableEquipAnimation
					write<float>(cache::local_pawn + CURRENT_WEAPON + 0x370, 0.00001f); // TimeToEquip
					write<bool>(cache::local_pawn + CURRENT_WEAPON + 0x1489, true); // bIgnoreTryToFireSlotCooldownRestriction
				}
				else {
					//printf("no weapon!\r\n");
				}
			}

			if (settings::exploits::bFullAutoWeapons)
			{
				if (cache::local_pawn && cache::current_weapon)
				{
					//uintptr_t WeaponData = read<float>(LocalPtrs::currentWeapon + 0x510); // weapon data

					 //uint8_t TriggerType = read<uint8_t>(WeaponData + 0x510 + 0x23c); // TriggerType

					write<uint8_t>(cache::current_weapon + 0x510 + 0x23c, (uint8_t)1); // EFortWeaponTriggerType__Automatic


					// bTargetingPreventsReload 
				}
			}

			if (settings::exploits::aimwhilejumping)
			{
				MASK
					write<bool>(cache::local_pawn + 0x5659, true);  // bTraceThroughWorld //https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=AFortPlayerPawnAthena&member=bADSWhileNotOnGround
			}
			else
			{
				MASK
					write<bool>(cache::local_pawn + 0x5659, false);  // bTraceThroughWorld //https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=AFortPlayerPawnAthena&member=bADSWhileNotOnGround
			}

			if (settings::exploits::doublepump) {
				if (cache::local_pawn) {
					uintptr_t CurrentWeapon = read<float>(cache::local_pawn + 0xA68);
					//auto weapon = read<uintptr_t>(cache::local_pawn + 0xA68);
					if (CurrentWeapon) {
						*(bool*)(CurrentWeapon + bIgnoreTryToFireSlotCooldownRestriction) = true;
					}
				}
			}

			if (settings::exploits::spinbot)
			{
				MASK
					auto Mesh = read<uint64_t>(cache::local_pawn + MESH);
				static auto Cached = read<Vector3>(Mesh + 0x140);

				if (GetAsyncKeyState(VK_LBUTTON)) {
					write<Vector3>(Mesh + 0x140, Vector3(1, rand() % 361, 1));
				}
				else write<Vector3>(Mesh + 0x140, Cached);
			}

			if (settings::exploits::overheat)
			{
				MASK
					float TimeHeatWasLastAdded = read<float>(cache::local_pawn + 0x1c9c);
				float TimeOverheatedBegan = read<float>(cache::local_pawn + 0x1ca0);
				float OverheatValue = read<float>(cache::local_pawn + 0x1c94);
				float WeaponOverheatedAnimation = read<float>(cache::local_pawn + 0x1c88);
				uintptr_t CurrentWeapon = read<float>(cache::local_pawn + 0xA68);

				if (TimeHeatWasLastAdded != 0.f or TimeOverheatedBegan != 0.f or OverheatValue != 0.f or WeaponOverheatedAnimation != 0.f) {
					write<float>(CurrentWeapon + 0x14d4, 0.f);
					write<float>(CurrentWeapon + 0x14d8, 0.f);
					write<float>(CurrentWeapon + 0x14cc, 0.f);
					write<float>(CurrentWeapon + 0x14c0, 0.f);
				}
			}

			if (settings::exploits::bRapidFire)
			{
				//printf("rapid fire !\r\n");
				if (cache::current_weapon)
				{
					//printf(" weapon !\r\n");

					write<float>(cache::current_weapon + 0xe44, 0); // LastFireTime
					write<float>(cache::current_weapon + 0xe48, 0); // LastFireTimeVerified
				}
				else {
					//printf("no weapon !\r\n");
				}
			}

			if (settings::exploits::FirstPerson)
			{
				write<bool>(cache::player_controller + OnSetFirstPersonCamera + 0x10 + 0x18, true);
			}

			if (settings::exploits::instaReboot)
			{
				float ResurrectionStartDelay = read<float>(cache::local_pawn + InteractingRebootVan + Resurrection_StartDelay); ////AFortPlayerStateAthena InteractingRebootVan
				if (ResurrectionStartDelay != 0.001f)
				{
					write<float>(cache::local_pawn + InteractingRebootVan + Resurrection_StartDelay, 0.001f); //ABuildingGameplayActorSpawnMachine ResurrectionStartDelay 
				}

			}
			if (settings::exploits::NoEquipAnimation)
			{

				uintptr_t CurrentWeapon = read<uintptr_t>(cache::local_pawn + CURRENT_WEAPON); //CurrentWeapon Offset
				if (CurrentWeapon) {
					write<bool>(CurrentWeapon + bDisableEquipAnimation, true); //bDisableEquipAnimation Offset 
				}

			}

			if (settings::exploits::instantrevive) {
				write<float>(cache::local_pawn + Revivefromdbnotime, 1); //ReviveFromDBNOTime 
			}

			if (settings::exploits::vehicle_nocooldodwn) {
				write<float>(cache::local_pawn + 0xF0, 100);
			}

			if (settings::exploits::autorun)
			{
				write<char>(cache::player_controller + bautorunon, -1); //bautorunon testing
			}

			if (settings::exploits::creative_fly)
			{
				if (uintptr_t CharacterMovement = read<uintptr_t>(cache::local_pawn + 0x320)) // CharacterMovement = 0x320;
				{
					// Ensure the player wants to fly or swing
					write<short>(CharacterMovement + bWantsToSwing, 257);
					// Set a very high attachment location to potentially negate gravity
					write<Vector3>(CharacterMovement + SwingAttachLocation, Vector3{ 0.0, 0.0, 10000000.0 });
					// Enable instant velocity change
					write<bool>(CharacterMovement + bSwingInstantVelocity, true);

					// Apply upward force continuously while space is pressed
					if (GetAsyncKeyState(VK_SPACE))
					{
						// Apply a strong continuous upward force
						write<Vector3>(CharacterMovement + SwingLaunch, Vector3{ 0.0, 0.0, 10000.0 });
					}
					else
					{
						// Zero out forces when no keys are pressed to stop unintended movement
						write<Vector3>(CharacterMovement + SwingLaunch, Vector3{ 0.0, 0.0, 0.0 });
					}

					// Optional: Check for SHIFT key to apply horizontal movement
					if (GetAsyncKeyState(VK_SHIFT))
					{
						// This block applies directional movement; you might want to adjust or remove it if it interferes with the ascent
						double Angle;

						Angle = camera.rotation.y * (M_PI / 180.0);
						double sy = sin(Angle);
						double cy = cos(Angle);

						Angle = -camera.rotation.x * (M_PI / 180.0);
						double sp = sin(Angle);
						double cp = cos(Angle);

						// Apply horizontal movement while maintaining upward motion
						write<Vector3>(CharacterMovement + SwingLaunch, Vector3{ cp * cy * 500.0, cp * sy * 500.0, 5000.0 });
					}

					// Optional: Check for CONTROL key to move downward
					if (GetAsyncKeyState(VK_CONTROL))
					{
						// Apply a downward force
						write<Vector3>(CharacterMovement + SwingLaunch, Vector3{ 0.0, 0.0, -5000.0 });
					}
				}
			}


			if (settings::exploits::AirStuck) {

				if (GetAsyncKeyState(VK_LSHIFT)) {
					write<float>(cache::local_pawn + 0x68, 0);

				}
				else {
					write<float>(cache::local_pawn + 0x68, 1);
				}
			}

			if (settings::exploits::carfly)
			{
				MASK
					uintptr_t CurrentVehicle = read<DWORD_PTR>(cache::local_pawn + 0x2a18); // CurrentVehicle

				if (CurrentVehicle && GetAsyncKeyState(VK_SPACE))
				{
					write<bool>(CurrentVehicle + 0x87a, false); // bUseGravity : 1
				}
				else {
					write<bool>(CurrentVehicle + 0x87a, true); // bUseGravity : 1
				}

			}


			auto dist = getCrossDistance(head2d.x, head2d.y, settings::width / 2, settings::height / 2);
			if (dist <= settings::aimbot::fov && dist < cache::closest_distance)
			{
				cache::closest_distance = dist;
				cache::closest_mesh = mesh;
			}
	}
}