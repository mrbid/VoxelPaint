# Voxel Paint
Paint in 3D using voxels.

![screenshot](https://dashboard.snapcraft.io/site_media/appmedia/2023/07/Screenshot_2023-07-07_01-56-44_oXveCB3.png)

## Snapcraft
https://snapcraft.io/voxelpaint

## Info
Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.

* **W,A,S,D** = Move around based on relative orientation to X and Y.
* **L-SHIFT + SPACE** = Move up and down relative Z.
* **2-3 / Mouse Scroll Wheel** = Change texture of pointed node.
* **E / Left Click** = Place node.
* **Q / Right Click** = Delete node.
* **F / Mouse4 Click** = Toggle player fast speed on and off.
* **1 / Middle Click** = Copys texture of pointed node.
* **R** = Resets view and position matrix.
* **F3** = Save. *(saves automatically on exit or idle for more than 3 minutes)*
* **F8** = Load. *(will erase what you have done since the last save)*

Arrow Keys can be used to move the view around.

Your state is automatically saved on exit.

You can customize the 19 block tileset, in your prefPath you will find a `tiles.ppm` image file, edit this file and save it as a ppm with a `P6 272 16 255` header. [Krita](https://krita.org) can edit ppm files.
