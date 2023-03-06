workspace "Robles"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Robles"
	location "Robles"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RS_PLATFORM_WINDOWS",
			"RS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Encino/\"")
		}

	filter "configurations:Debug"
		defines "RS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RS_DIST"
		optimize "On"

project "Encino"
	location "Encino"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Robles/vendor/spdlog/include",
		"Robles/src"
	}

	links
	{
		"Robles"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RS_DIST"
		optimize "On"