################################################################################
# Emerging technologies, Systems & Security
#
#   date: April 19th 2024
#   author: VlJo
################################################################################
# Script to generate a Vivado project for HW/SW codesign (400)
#
################################################################################

# set parameters
set pname "hwswcodesign_400"
set srcpath "C:/Users/jonas/Documents/shallow_root_file/hwsw_co_design/forked_repo/src/project/hdl"
set projpath "C:\Users\jonas\Documents\shallow_root_file\hwsw_co_design\Project\Software"
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


