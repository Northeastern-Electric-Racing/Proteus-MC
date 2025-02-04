#ifndef PROTEUS_FAULT_H
#define PROTEUS_FAULT_H

#include "cmsis_os.h"

typedef enum
{
    DEFCON1 = 1,
    DEFCON2,
    DEFCON3,
    DEFCON4,
    DEFCON5
} fault_sev_t;

// TODO: add actual fault codes
typedef enum
{
    FAULTS_CLEAR = 0x0,
    MAX_FAULTS
} fault_code_t;

typedef struct
{
    fault_code_t id;
    fault_sev_t severity;
    char *diag;
} fault_data_t;

/* Function to queue a fault */
int queue_fault(fault_data_t *fault_data);

/* Defining Fault Handler Task */
void vFaultHandler(void *pv_params);
extern osThreadId_t fault_handle;
extern const osThreadAttr_t fault_handle_attributes;

#endif // FAULT_H
