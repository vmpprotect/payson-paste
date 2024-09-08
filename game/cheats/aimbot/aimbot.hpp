#pragma once
#include "../../../includes.hpp"

void mouseAim(uintptr_t target_mesh)
{
	MASK
	if (!target_mesh) return;
	if (!is_visible(target_mesh)) return;

	int bone_id = settings::aimbot::current_hitbox;
	Vector3 head3d = get_entity_bone(target_mesh, bone_id);

	/*
	if (settings::aimbot::bulletPrediction)
	{
		float projectileVelocity = read<float>(cache::current_weapon + VELOCITY);
		float projectileGravity = read<float>(cache::current_weapon + GRAVITY);

		if (projectileVelocity > 0)
		{
			float height = head3d.z - cache::local_camera.location.z;
			float depthPlayerTarget = sqrt(pow(head3d.y - cache::local_camera.location.y, 2) * pow(head3d.x - cache::local_camera.location.x, 2));
			float bulletDrop = getBulletDrop(height, depthPlayerTarget, projectileVelocity, projectileGravity);

			head3d.z += bulletDrop;
		}
	}
	*/

	Vector2 head2d = project_world_to_screen(head3d);
	Vector2 target{};

	if (head2d.x != 0)
	{
		if (head2d.x > settings::screen_center_x)
		{
			target.x = -(settings::screen_center_x - head2d.x);
			target.x /= settings::aimbot::smoothness;
			if (target.x + settings::screen_center_x > settings::screen_center_x * 2) target.x = 0;
		}
		if (head2d.x < settings::screen_center_x)
		{
			target.x = head2d.x - settings::screen_center_x;
			target.x /= settings::aimbot::smoothness;
			if (target.x + settings::screen_center_x < 0) target.x = 0;
		}
	}
	if (head2d.y != 0)
	{
		if (head2d.y > settings::screen_center_y)
		{
			target.y = -(settings::screen_center_y - head2d.y);
			target.y /= settings::aimbot::smoothness;
			if (target.y + settings::screen_center_y > settings::screen_center_y * 2) target.y = 0;
		}
		if (head2d.y < settings::screen_center_y)
		{
			target.y = head2d.y - settings::screen_center_y;
			target.y /= settings::aimbot::smoothness;
			if (target.y + settings::screen_center_y < 0) target.y = 0;
		}
	}

	input::move_mouse(target.x, target.y);
	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(target.x), static_cast<DWORD>(target.y), NULL, NULL);
	return;
}

void silentAim(uintptr_t target_mesh)
{
	MASK
	if (!target_mesh) return;
	if (!is_visible(target_mesh)) return;

	Vector3 head3d = get_entity_bone(target_mesh, 110);
	Vector2 head2d = project_world_to_screen(getLoc(head3d));
	uintptr_t PlayerCameraManager = read<uintptr_t>(cache::player_controller + 0x348); // https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=APlayerController&member=PlayerCameraManager 
	uintptr_t ViewYawMin = 0x2494; // APlayerCameraManager > ViewYawMin
	uintptr_t ViewYawMax = 0x2498; // APlayerCameraManager > ViewYawMax
	uintptr_t AimPitchMin = 0x1830; // AFortWeaponRanged > AimPitchMin
	uintptr_t AimPitchMax = 0x1834; // AFortWeaponRanged > AimPitchMax

	if (head2d.x != 0 || head2d.y != 0)
	{
		if (cache::current_weapon)
		{
			Vector3 NewRotation = calculateNewRotation(cache::local_camera.location, head3d);
			static float OrginalPitchMin = read<float>(PlayerCameraManager + ViewYawMin);
			static float OrginalPitchMax = read<float>(PlayerCameraManager + ViewYawMax);
			
			//write<float>(cache::current_weapon + AimPitchMin, NewRotation.x);
			//write<float>(cache::current_weapon + AimPitchMax, NewRotation.x);
			//write<float>(PlayerCameraManager + ViewYawMin, NewRotation.y);
			//write<float>(PlayerCameraManager + ViewYawMax, NewRotation.y);
			//Sleep(5);
			//write<float>(PlayerCameraManager + ViewYawMin, OrginalPitchMin);
			//write<float>(PlayerCameraManager + ViewYawMax, OrginalPitchMax);
		}
	}
}
