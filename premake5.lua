workspace "CHIP-8"
	architecture "x64"
	startproject "CHIP-8"
	configurations {"Debug", "Release"}

	outputdir = "%{cfg.buildcfg}/%{cfg.system}_%{cfg.architecture}/%{prj.name}"

	-- Includes
	IncludeDir = {}
	--IncludeDir["SDL"] = "CHIP-8/vendor/SDL/include"

	group "Dependancies"
	group ""

	project "CHIP-8"
		location "CHIP-8"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"

		targetdir("%{wks.location}/bin/" .. outputdir)
		objdir("%{wks.location}/bin-int/" .. outputdir)
		debugdir("%{wks.location}/bin/" .. outputdir)

		pchheader "pch.h"
		pchsource "%{prj.name}/src/pch.cpp"

		files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

		defines {"_CRT_SECURE_NO_WARNINGS"}

		includedirs {
			"%{prj.name}/src"
			--"%{IncludeDir.SDL}"
		}

		links {
			"SDL2"
		}

		filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		filter "configurations:Release"
		runtime "Release"
		optimize "on"