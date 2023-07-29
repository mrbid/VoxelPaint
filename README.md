# Voxel Paint
Paint in 3D using voxels.

[![screenshot](https://dashboard.snapcraft.io/site_media/appmedia/2023/07/Screenshot_2023-07-07_01-56-44_oXveCB3.png)](https://www.youtube.com/watch?v=op3-aAQyGIA)

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
* Multi Selection = Middle Mouse Click & Drag *(or Q and drag)* to select area. Fill the nodes with **B** or delete them with **N**. **Middle Scroll** or **X+C** to change texture.

Arrow Keys can be used to move the view around.

Your state is automatically saved on exit.

You can customize the 17 block tileset, in your dataPath you will find a `tiles.ppm` image file, edit this file and save it as a PPM with a `P6 272 16 255` header. [Krita](https://krita.org) or [KolourPaint](https://apps.kde.org/en-gb/kolourpaint/) can edit PPM files.

You can change the mouse sensitivity by passing the new sensitivity as the 1st command line parameter default is 0.003 `./vox 0.003`.
