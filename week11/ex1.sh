fallocate -l 100M lofs.img
losetup -f lofs.img
sudo mkfs.ext4 lofs.img
mkdir lofsdisk
sudo mount lofs.img lofsdisk
