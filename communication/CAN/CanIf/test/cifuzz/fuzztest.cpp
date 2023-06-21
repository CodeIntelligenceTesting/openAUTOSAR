#include <stdint.h>
#include <stddef.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>


extern "C" {
    #include "CanIf.h"
    #include "CanIf_Cbk.h"
    #include "PduR_Com.h"
}

void mocklib_set_data(void *fuzzed_data_provider);
void ConsumeDataAndFillRestWithZeros(void *destination, size_t num_bytes, FuzzedDataProvider *fuzzed_data);

FUZZ_TEST_SETUP() {}

FUZZ_TEST(const uint8_t *data, size_t size) {
    
    // Ensure a minimum data length
    if (size < 100) return;

    // Setup FuzzedDataProvider and initialize the mocklib
    FuzzedDataProvider fuzzed_data(data, size);
    mocklib_set_data(&fuzzed_data);

    int number_of_functions = fuzzed_data.ConsumeIntegralInRange<int>(1, 100);
    for (int i = 0; i < number_of_functions; i++) {
        int func_id = fuzzed_data.ConsumeIntegralInRange<int>(0, 12);
        switch(func_id) {
            case 0: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                Can_Arc_ErrorType error = {
                        .R = fuzzed_data.ConsumeIntegral<uint32_t>()
                };
                CanIf_Arc_Error(fuzz_int_0, error);
                break;
            }
            case 1: {
                CanIf_Arc_ChannelIdType enum_0 = (CanIf_Arc_ChannelIdType) fuzzed_data.ConsumeIntegralInRange(0, (int) CANIF_CHANNEL_CNT);
                CanIf_Arc_GetChannelDefaultConfIndex(enum_0);
                break;
            }
            case 2: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_ControllerBusOff(fuzz_int_0);
                break;
            }
            case 3: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_ControllerModeType enum_0 = (CanIf_ControllerModeType)0;
                ConsumeDataAndFillRestWithZeros(&enum_0, sizeof(enum_0), &fuzzed_data);
                CanIf_GetControllerMode(fuzz_int_0, &enum_0);
                break;
            }
            case 4: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_ChannelGetModeType enum_0 = (CanIf_ChannelGetModeType)0;
                ConsumeDataAndFillRestWithZeros(&enum_0, sizeof(enum_0), &fuzzed_data);
                CanIf_GetPduMode(fuzz_int_0, &enum_0);
                break;
            }
            case 5: {
                CanIf_Init(&CanIf_Config);
                break;
            }
            case 6: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                uint8 fuzz_int_1 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_InitController(fuzz_int_0, fuzz_int_1);
                break;
            }
            case 7: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                uint32 fuzz_int_1 = fuzzed_data.ConsumeIntegral<uint32>();
                std::vector<uint8_t> fuzzed_data_0 = fuzzed_data.ConsumeBytes<uint8_t>(fuzzed_data.ConsumeIntegral<uint8_t>());
                size_t fuzz_size_0 = fuzzed_data_0.size();
                CanIf_RxIndication(fuzz_int_0, fuzz_int_1, fuzz_size_0, fuzzed_data_0.data());
                break;
            }
            case 8: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_ControllerModeType enum_0 = (CanIf_ControllerModeType) fuzzed_data.ConsumeIntegralInRange(0, (int) CANIF_CS_SLEEP);
                CanIf_SetControllerMode(fuzz_int_0, enum_0);
                break;
            }
            case 9: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_ChannelSetModeType enum_0 = (CanIf_ChannelSetModeType) fuzzed_data.ConsumeIntegralInRange(0, (int) CANIF_SET_TX_OFFLINE_ACTIVE);
                CanIf_SetPduMode(fuzz_int_0, enum_0);
                break;
            }
            case 10: {
                uint8 fuzz_int_0 = fuzzed_data.ConsumeIntegral<uint8>();
                CanIf_SetWakeupEvent(fuzz_int_0);
                break;
            }
            case 11: {
                PduIdType fuzz_int_0 = fuzzed_data.ConsumeIntegral<PduIdType>();
                PduInfoType struct_0 = {0};
                ConsumeDataAndFillRestWithZeros(&struct_0, sizeof(struct_0), &fuzzed_data);
                CanIf_Transmit(fuzz_int_0, &struct_0);
                break;
            }
            case 12: {
                PduIdType fuzz_int_0 = fuzzed_data.ConsumeIntegral<PduIdType>();
                CanIf_TxConfirmation(fuzz_int_0);
                break;
            }
        }
    }
}
