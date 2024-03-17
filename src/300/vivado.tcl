################################################################################
# Emerging technologies, Systems & Security
#
#   date: January 15th 2024
#   author: VlJo
################################################################################
# Script to generate a Vivado project for HW/SW codesign (100)
#
################################################################################

# set parameters
set pname "PicoRV32VivadoProject"
set srcpath "C:/Users/jonas/Documents/shallow_root_file/hwsw_co_design/forked_repo/src/300/hdl"
set projpath "C:/Users/jonas/Documents/shallow_root_file/hwsw_co_design/Oefeningen/Week5_6"
set part "xc7z020clg400-1"
set board "tul.com.tw:pynq-z2:part0:1.0"

# delete older versions
cd $projpath
exec rm -Rf $pname

# create project
create_project $pname $projpath/$pname -part $part
set_property board_part $board [current_project]
set_property target_language VHDL [current_project]



# add VHDL source files
set fnames [glob -directory $srcpath -- "*.vhd"]
foreach fname $fnames {
    add_files $fname
}

# add verilog source files
set fnames [glob -directory $srcpath -- "*.v"]
foreach fname $fnames {
    add_files $fname
}

# add simulation source files
set fnames [glob -directory $srcpath/tb -- "*.vhd"]
foreach fname $fnames {
    add_files -fileset sim_1 $fname
}

# add constraint files
set fnames [glob -directory $srcpath/../xdc -- "*.xdc"]
foreach fname $fnames {
    add_files -fileset constrs_1 $fname
}


set_property STEPS.SYNTH_DESIGN.ARGS.ASSERT true [get_runs synth_1]
set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]