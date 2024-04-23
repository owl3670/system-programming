//#pragma warning(disable:4100)

#include <ntddk.h>

void DriverUnload(PDRIVER_OBJECT pDriver){
    UNREFERENCED_PARAMETER(pDriver);

    DbgPring("DriverUnload");

    //KdPrint(("AAAA"));
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT pDriver,
                                PUNICODE_STRING pRegPath){
    DbgPring("DriverEntry : %p\n", pDriver);

    pDriver->DriverUnload = DriverUnload;

    return STATUS_SUCCESS;
}