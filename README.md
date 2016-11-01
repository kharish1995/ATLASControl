Setting up workspace

Create catkin workspace,

    mkdir -p ~/atlas_ws/src 
    cd ~/atlas_ws/src
    catkin_init_workspace
    cd ~/atlas_ws
    catkin_make
    
Download the ATLASSimInterface_3.0.2.zip shared on the drive and upack it in your home directory 

Clone the git repository

    git clone  https://github.com/HarishKarunakaran/ATLASControl.git 
    
    cd atlas_interface
    gedit CMakeLists.txt
    Modify the following line giving the location to where you unzipped AtlasSimInterface_3.0.2
    
    set(ENV{ATLAS_ROBOT_INTERFACE_ROOT} "/home/yourname/AtlasSimInterface_3.0.2")

Now run catkin_make,

    cd ~/atlas_ws    
    catkin_make

Packages

    atlas_control
    Package to write the force control
    atlas_interface
    Contains the Full-body controller
