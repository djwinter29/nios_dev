# nios_dev
This project is trying to provide the tiny sehcduler to enable NIOS II software core achieve multi-thread.

To reduce the size, all task should be set at the beginning of the application.

The entire scheduler is trying to use static memory as possible. and trying to avoid dynamic memory allocation completely.

There is no stack-overflow check, and there is no heap managment implmented(Altera BSP have not implement)
be careful to use malloc call from newlib, it could be dangerous.

In order to work, please use the BSP editer:
1. In "software packages" tab, enable irq_handler module
2. In "Enable File Generation" tab, diable the following files:(these files have been re-implemented on the above software packages)
        alt_exception_entry.S           Drivers/altera_nios2_gen2_hal_drivers/HAL/src
        alt_irq_entry.S                 Drivers/altera_nios2_gen2_hal_drivers/HAL/src
        alt_iic_isr_register.c          Operating System/src



