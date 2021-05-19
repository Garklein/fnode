{
	"targets": [
		{
			"target_name": "main",
			"sources": [ "src/main.cpp" ], # relative to this file
			"libraries": [ "../src/fortran.o" ] # but libraries are relative to the .vcxproj file for some reason
		}
	]
}
