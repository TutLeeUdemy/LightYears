add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/spaceship/Spaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/spaceship/Spaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerSpaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerSpaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Shooter.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Shooter.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/BulletShooter.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/BulletShooter.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/ThreeWayShooter.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/ThreeWayShooter.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/FrontalWiper.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/FrontalWiper.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/weapon/Bullet.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/weapon/Bullet.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/gameplay/HealthComponent.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameplay/HealthComponent.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/include/VFX/Explosion.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/VFX/Explosion.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/EnemySpaceship.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/EnemySpaceship.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/Vanguard.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/Vanguard.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/VanguardStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/VanguardStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/TwinBlade.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/TwinBlade.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/UFO.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/UFO.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/UFOStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/UFOStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/Hexagon.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/Hexagon.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/HexagonStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/HexagonStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/TwinBladeStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/TwinBladeStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/ChaosStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/ChaosStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/Boss.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/Boss.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Enemy/BossStage.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Enemy/BossStage.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Level/GameLevelOne.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Level/GameLevelOne.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/Level/MainMenuLevel.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Level/MainMenuLevel.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/player/Reward.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/Reward.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/player/Player.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/Player.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/GameplayHUD.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/GameplayHUD.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/include/widgets/MainMenuHUD.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/widgets/MainMenuHUD.cpp



	${CMAKE_CURRENT_SOURCE_DIR}/include/player/PlayerManager.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/player/PlayerManager.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibDirToTarget(${LIGHT_YEARS_ENGINE_TARGET_NAME} ${LIGHT_YEARS_GAME_TARGET_NAME})

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
	TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${RESOURCE_SRC_DIR}
	$<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
	"config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)