--------------------------------------------------------------------------------
-- KU Leuven - ESAT/COSIC- Embedded Systems & Security
--------------------------------------------------------------------------------
-- Module Name:     picorv_testbench - Behavioural
-- Project Name:    Testbench for PicoRV32
-- Description:     
--
-- Revision     Date       Author     Comments
-- v0.1         20211218   VlJo       Initial version
--
--------------------------------------------------------------------------------

library IEEE;
    use IEEE.STD_LOGIC_1164.ALL;
    -- use IEEE.NUMERIC_STD.ALL;

library work;
    use work.PKG_hwswcodesign.ALL;

entity soc_tb is
end entity soc_tb;

architecture Behavioural of soc_tb is

    signal resetn_i : STD_LOGIC;
    signal clock_i : STD_LOGIC;

    signal PADDR_mem_i, PADDR_print_i, PADDR_sensor_i : STD_LOGIC_VECTOR(C_DATA_WIDTH-1 downto 0);
    signal PPROT_mem_i, PPROT_print_i, PPROT_sensor_i : STD_LOGIC_VECTOR(C_PROT_WIDTH-1 downto 0);
    signal PSELx_mem_i, PSELx_print_i, PSELx_sensor_i : STD_LOGIC;
    signal PENABLE_mem_i, PENABLE_print_i, PENABLE_sensor_i : STD_LOGIC;
    signal PWRITE_mem_i, PWRITE_print_i, PWRITE_sensor_i : STD_LOGIC;
    signal PWDATA_mem_i, PWDATA_print_i, PWDATA_sensor_i : STD_LOGIC_VECTOR(C_DATA_WIDTH-1 downto 0);
    signal PSTRB_mem_i, PSTRB_print_i, PSTRB_sensor_i : STD_LOGIC_VECTOR(C_STRB_WIDTH-1 downto 0);
    signal PREADY_mem_i, PREADY_print_i, PREADY_sensor_i : STD_LOGIC;
    signal PRDATA_mem_i, PRDATA_print_i, PRDATA_sensor_i : STD_LOGIC_VECTOR(C_DATA_WIDTH-1 downto 0);
    signal PSLVERR_mem_i, PSLVERR_print_i, PSLVERR_sensor_i : STD_LOGIC;

    constant clock_period : time := 10 ns;

begin

    -------------------------------------------------------------------------------
    -- STIMULI
    -------------------------------------------------------------------------------
    -- reset_combined_n <= resetn_i and reset_processor_ni;
    PSTIM: process
    begin
        resetn_i <= '0';
        wait for clock_period * 10;

        resetn_i <= '1';
        wait for clock_period * 10;

        wait;
    end process;

    -------------------------------------------------------------------------------
    -- DUT
    -------------------------------------------------------------------------------
    soc_inst00: component soc port map(
        PCLK => clock_i,
        PRESETn => resetn_i,
        PADDR_mem => PADDR_mem_i,
        PPROT_mem => PPROT_mem_i,
        PSELx_mem => PSELx_mem_i,
        PENABLE_mem => PENABLE_mem_i,
        PWRITE_mem => PWRITE_mem_i,
        PWDATA_mem => PWDATA_mem_i,
        PSTRB_mem => PSTRB_mem_i,
        PREADY_mem => PREADY_mem_i,
        PRDATA_mem => PRDATA_mem_i,
        PSLVERR_mem => PSLVERR_mem_i,
        PADDR_print => PADDR_print_i,
        PPROT_print => PPROT_print_i,
        PSELx_print => PSELx_print_i,
        PENABLE_print => PENABLE_print_i,
        PWRITE_print => PWRITE_print_i,
        PWDATA_print => PWDATA_print_i,
        PSTRB_print => PSTRB_print_i,
        PREADY_print => PREADY_print_i,
        PRDATA_print => PRDATA_print_i,
        PSLVERR_print => PSLVERR_print_i,
        PADDR_sensor => PADDR_sensor_i,
        PPROT_sensor => PPROT_sensor_i,
        PSELx_sensor => PSELx_sensor_i,
        PENABLE_sensor => PENABLE_sensor_i,
        PWRITE_sensor => PWRITE_sensor_i,
        PWDATA_sensor => PWDATA_sensor_i,
        PSTRB_sensor => PSTRB_sensor_i,
        PREADY_sensor => PREADY_sensor_i,
        PRDATA_sensor => PRDATA_sensor_i,
        PSLVERR_sensor => PSLVERR_sensor_i
    );

    -------------------------------------------------------------------------------
    -- MEMORY MODEL
    -------------------------------------------------------------------------------
    APB_mem_model_inst00: component APB_mem_model
        generic map (
            G_BASE_ADDRESS => C_BASE_ADDRESS_0,
            G_HIGH_ADDRESS => C_HIGH_ADDRESS_0,
            FNAME_HEX => "/home/jvliegen/vc/github/KULeuven-Diepenbeek/course_hwswcodesign_internal/project/firmware/v1_0_0/firmware.hex"
        ) port map (
            resetn => resetn_i,
            clock => clock_i,
            PADDR => PADDR_mem_i, 
            PPROT => PPROT_mem_i, 
            PSELx => PSELx_mem_i, 
            PENABLE => PENABLE_mem_i, 
            PWRITE => PWRITE_mem_i, 
            PWDATA => PWDATA_mem_i, 
            PSTRB => PSTRB_mem_i, 
            PREADY => PREADY_mem_i, 
            PRDATA => PRDATA_mem_i, 
            PSLVERR => PSLVERR_mem_i
        );

    -------------------------------------------------------------------------------
    -- PRINT MODEL
    -------------------------------------------------------------------------------
    APB_print_model_inst00: component APB_print_model generic map(
            G_BASE_ADDRESS => C_BASE_ADDRESS_1,
            G_HIGH_ADDRESS => C_HIGH_ADDRESS_1,
            FNAME_OUT => "/home/jvliegen/vc/github/KULeuven-Diepenbeek/course_hwswcodesign_internal/project/firmware/v1_0_0/simulation_output.dat"
        ) port map (
            resetn => resetn_i,
            clock => clock_i,
            PADDR => PADDR_print_i,
            PPROT => PPROT_print_i,
            PSELx => PSELx_print_i,
            PENABLE => PENABLE_print_i,
            PWRITE => PWRITE_print_i,
            PWDATA => PWDATA_print_i,
            PSTRB => PSTRB_print_i,
            PREADY => PREADY_print_i,
            PRDATA => PRDATA_print_i,
            PSLVERR => PSLVERR_print_i
        );

    -------------------------------------------------------------------------------
    -- SENSOR MODEL
    -------------------------------------------------------------------------------
    APB_sensor_model_inst00: component APB_sensor_model generic map(
            G_BASE_ADDRESS => C_BASE_ADDRESS_3,
            G_HIGH_ADDRESS => C_HIGH_ADDRESS_3,
            FNAME_DATA => "/home/jvliegen/vc/github/KULeuven-Diepenbeek/course_hwswcodesign_internal/project/data/sensorreading.dat"
        ) port map (
            resetn => resetn_i,
            clock => clock_i,
            PADDR => PADDR_sensor_i,
            PPROT => PPROT_sensor_i,
            PSELx => PSELx_sensor_i,
            PENABLE => PENABLE_sensor_i,
            PWRITE => PWRITE_sensor_i,
            PWDATA => PWDATA_sensor_i,
            PSTRB => PSTRB_sensor_i,
            PREADY => PREADY_sensor_i,
            PRDATA => PRDATA_sensor_i,
            PSLVERR => PSLVERR_sensor_i
        );

    -------------------------------------------------------------------------------
    -- CLOCK
    -------------------------------------------------------------------------------
    PCLK: process
    begin
        clock_i <= '1';
        wait for clock_period/2;
        clock_i <= '0';
        wait for clock_period/2;
    end process PCLK;

end Behavioural;
