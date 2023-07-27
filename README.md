# Voxel Paint
Paint in 3D using voxels.

![screenshot](https://dashboard.snapcraft.io/site_media/appmedia/2023/07/Screenshot_2023-07-07_01-56-44_oXveCB3.png)

## Flathub
https://flathub.org/apps/com.voxdsp.VoxelPaint

## Snapcraft
https://snapcraft.io/voxelpaint

## Info
Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.

* W,A,S,D = Move around based on relative orientation to X and Y.
* SPACE + L-SHIFT = Move up and down relative Z.
* Left Click / R-SHIFT = Place node.
* Right Click / R-CTRL = Delete node.
* E / F / Mouse4 = Toggle player fast speed on and off.
* 1-7 = Change move speed for selected fast state.
* Q / Middle Click = Clone texture of pointed node.
* Mouse Scroll / Slash + Quote / X + C = Change texture of pointed node.
* T = Resets view and position matrix.
* R / G = Gravity on/off.
* F3 = Save. (auto saves on exit or idle for more than 3 minutes)
* F8 = Load. (will erase what you have done since the last save)
* F10 = Export the VoxelPaint data to a zip file in $HOME/Documents.
* **Multi Selections** Middle Mouse Click & Drag to select area, once selected
you can fill the area using the V key or change the nodes
with the mouse scroll, there are no keyboard binds for multi selections.

Arrow Keys can be used to move the view around.

Your state is automatically saved on exit.

You can customize the 19 block tileset, in your dataPath you will find a `tiles.ppm` image file, edit this file and save it as a ppm with a `P6 272 16 255` header. [Krita](https://krita.org) can edit ppm files.
