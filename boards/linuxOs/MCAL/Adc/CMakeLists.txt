#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
add_library ( Adc STATIC src/Adc_Internal.c
                )
                target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/include )
                target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Adc/include )
                target_include_directories(Adc PUBLIC ${PROJECT_SOURCE_DIR}/boards/linuxOs/MCAL/Os/include )
