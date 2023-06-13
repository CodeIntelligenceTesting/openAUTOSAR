#include <assert.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

extern "C" {
#include "Std_Types.h"
#include "CanIf.h"
#include "CanIf_Cbk.h"
#include "CanIf_Types.h"
}

FUZZ_TEST_SETUP() {
    // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    // Ensure a minimum data length
    if(size < 100) return;

    // Setup FuzzedDataProvider and initialize the mocklib
    FuzzedDataProvider fuzz_data_provider(data, size);
    FuzzedDataProvider *fuzz_data = &fuzz_data_provider;

    int number_of_functions = fuzz_data->ConsumeIntegralInRange<int>(1,100);
    for (int i=0; i<number_of_functions; i++) {
        int func_id = fuzz_data->ConsumeIntegralInRange<int>(0, 12);
        switch(func_id) {
            case 0: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                Can_Arc_ErrorType error = {
                    .R = fuzz_data->ConsumeIntegral<uint32_t>()
                };
                CanIf_Arc_Error(fuzz_int_0, error);
                break;
            }
            case 1: {
                CanIf_Arc_ChannelIdType enum_0 = (CanIf_Arc_ChannelIdType) fuzz_data->ConsumeIntegralInRange(0, (int) CANIF_CHANNEL_CNT);
                CanIf_Arc_GetChannelDefaultConfIndex(enum_0);
                break;
            }
            case 2: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_ControllerBusOff(fuzz_int_0);
                break;
            }
            case 3: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_ControllerModeType fuzz_int_1;
                CanIf_GetControllerMode(fuzz_int_0, &fuzz_int_1);
                break;
            }
            case 4: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_ChannelGetModeType fuzz_int_1;
                CanIf_GetPduMode(fuzz_int_0, &fuzz_int_1);
                break;
            }
            case 5: {
                CanIf_Init(&CanIf_Config);
                break;
            }
            case 6: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                uint8 fuzz_int_1 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_InitController(fuzz_int_0, fuzz_int_1);
                break;
            }
            case 7: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                uint32 fuzz_int_1 = fuzz_data->ConsumeIntegral<uint32>();
                std::vector<uint8_t> fuzz_data_0 = fuzz_data->ConsumeBytes<uint8_t>(fuzz_data->ConsumeIntegral<uint8_t>());
                size_t fuzz_size_0 = fuzz_data_0.size();
                CanIf_RxIndication(fuzz_int_0, fuzz_int_1, fuzz_size_0, fuzz_data_0.data());
                break;
            }
            case 8: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_ControllerModeType enum_0 = (CanIf_ControllerModeType) fuzz_data->ConsumeIntegralInRange(0, (int) CANIF_CS_SLEEP);
                CanIf_SetControllerMode(fuzz_int_0, enum_0);
                break;
            }
            case 9: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_ChannelSetModeType enum_0 = (CanIf_ChannelSetModeType) fuzz_data->ConsumeIntegralInRange(0, (int) CANIF_SET_TX_OFFLINE_ACTIVE);
                CanIf_SetPduMode(fuzz_int_0, enum_0);
                break;
            }
            case 10: {
                uint8 fuzz_int_0 = fuzz_data->ConsumeIntegral<uint8>();
                CanIf_SetWakeupEvent(fuzz_int_0);
                break;
            }
            case 11: {
                PduIdType fuzz_int_0 = fuzz_data->ConsumeIntegral<PduIdType>();
                std::vector<uint8> pdu_data = fuzz_data->ConsumeBytes<uint8>(fuzz_data->ConsumeIntegral<uint8>());
                PduInfoType pdu_info = {
                    .SduDataPtr = pdu_data.data(),
                    .SduLength = (const uint16) pdu_data.size()
                };
                CanIf_Transmit(fuzz_int_0, &pdu_info);
                break;
            }
            case 12: {
                PduIdType fuzz_int_0 = fuzz_data->ConsumeIntegral<PduIdType>();
                CanIf_TxConfirmation(fuzz_int_0);
                break;
            }
        }
    }
}
