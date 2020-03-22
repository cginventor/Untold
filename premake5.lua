workspace "Untold"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"

project "Untold"
	location "Untold"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "utpch.h"
	pchsource "Untold/src/utpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UT_PLATFORM_WINDOWS",
			"UNTOLD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "UT_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "UT_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "UT_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
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
		"Untold/vendor/spdlog/include",
		"Untold/src"
	}
	
	links
	{
		"Untold"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UT_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "UT_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "UT_DIST"
		optimize "On"