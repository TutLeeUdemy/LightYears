add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/BackdropActor.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackdropActor.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/BackgroundLayer.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/BackgroundLayer.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Object.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Object.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/AssetManager.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/AssetManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/MathUtility.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/MathUtility.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/PhysicsSystem.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/PhysicsSystem.cpp


	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Delegate.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Delegate.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/VFX/Particle.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/VFX/Particle.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/TimerManager.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/TimerManager.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/gameplay/GameStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/GameStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/gameplay/WaitStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/WaitStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/HUD.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/HUD.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/Widget.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Widget.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/TextWidget.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/TextWidget.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/ValueGuage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ValueGuage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/ImageWidget.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/ImageWidget.cpp


	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/Button.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/Button.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
)

target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
	${SFML_LIB_NAME}
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.5.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio)

set(BOX2D_LIB_NAME Box2D)
FetchContent_Declare(
	${BOX2D_LIB_NAME}
	GIT_REPOSITORY https://github.com/erincatto/box2d
	GIT_TAG v2.4.1
	GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(${BOX2D_LIB_NAME})
target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC box2d)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(box2d ${LIGHT_YEARS_ENGINE_TARGET_NAME})
