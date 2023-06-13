#include "Can.h"
#include "Com.h"

// Can module stubs
const Can_ControllerConfigType CanControllerConfigData[1];
const Can_ConfigSetType CanConfigSetData;

void Can_InitController( uint8 controller, const Can_ControllerConfigType *config) {}

Can_ReturnType Can_SetControllerMode( uint8 Controller, Can_StateTransitionType transition ) {
    return CAN_OK;
}

Can_ReturnType Can_Write( Can_Arc_HTHType hth, Can_PduType *pduInfo ) {
    return CAN_OK;
}


// Com module stubs
void Com_RxIndication(PduIdType ComRxPduId, const PduInfoType* PduInfoPtr) {}

void Com_TxConfirmation(PduIdType ComTxPduId) {}


// Det module stubs
void Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId) {}
