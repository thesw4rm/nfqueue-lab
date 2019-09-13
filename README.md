# nfqueue-lab

This code is for the NFQueue live coding activity during the Linux Advanced Lab. Created in Fall 2019 Semester on 09/13/2019. 

It will be improved more soon with tags and releases, but by looking through the commits you can see code at different stages when coding the system. Obviously the only working solution is the final commit, but if you get confused during the live coding or want to see where you went wrong, take a look. 

## Prerequisites
  Make sure to have two Debian or Red Hat based VMs ready. If you only have one, you can clone it by copy pasting the disk file (VMDK, QCOW2, etc) to another location and making a brand new VM using that disk. 
  
  On Debian based systems install the following dependencies
    ```sudo apt install make cmake libnetfilter-queue-dev```
  
  On Red Hat based systems
    ```sudo yum install make cmake libnetfilter_queue-devel```
    
  After that make sure you have iptables on the system and ufw/firewalld is disabled (basically no firewall rules initially)
