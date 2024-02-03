# Voxel Paint
Paint in 3D using textured voxels, also check out [VoxelPaintPro](https://github.com/mrbid/VoxelPaintPro).

[![screenshot](https://dashboard.snapcraft.io/site_media/appmedia/2023/07/Screenshot_2023-07-29_03-11-25.png)](https://www.youtube.com/watch?v=op3-aAQyGIA)

### Available on [Flathub](https://flathub.org/apps/com.voxdsp.VoxelPaint) and [Snapcraft](https://snapcraft.io/voxelpaint).

## Info
* Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.
* Arrow Keys can be used to move the view around.
* Your state is automatically saved on exit. A backup `world.db2.idle` is updated every time no input is detected for over 3 minutes.
* You can customize the 17 block tileset, in your dataPath you will find a `tiles.ppm` image file, edit this file and save it as a PPM with a `P6 272 16 255` header. [Krita](https://krita.org) or [KolourPaint](https://apps.kde.org/en-gb/kolourpaint/) can edit PPM files.
* You can change the mouse sensitivity by passing the new sensitivity as the 1st command line parameter *[default is 0.003]* `./vox 0.003`.

## Input Bindings
* W,A,S,D = Move around based on relative orientation to X and Y.
* SPACE + L-SHIFT = Move up and down relative Z.
* Left Click / R-SHIFT = Place node.
* Right Click / R-CTRL = Delete node.
* Middle Scroll = Change selected color.
* Q / Middle Click = Clone texture of pointed node.
* R = Places node at your current position.
* E / F / Mouse4 = Toggle player fast speed on and off.
* 1-7 = Change move speed for selected fast state.
* X + C / Slash + Quote = Change texture of pointed node.
* T = Resets player state to start.
* G = Gravity on/off.
* P = Toggle pitch lock.
* F3 = Save. (auto saves on exit or idle for more than 3 minutes)
* F8 = Load. (will erase what you have done since the last save)
* F10 = Export the VoxelPaint data to a zip file in $HOME/EXPORTS.

## Multi Selection
* Middle Mouse Click & Drag *(or Q and drag)* to select area.
* V = Copies the selected nodes to the currently pointed position, the point you started the selection from is the point you will copy from at the new pointed location.
* B = Fill selected nodes with selected color.
* N = Delete selected nodes.

## Known Bugs
* Sometimes when a selection is cloned and pasted a single line of nodes on the edge of the selection will not be copied, this is easy to fix by doing a second copy or placing two nodes around the selection area using (R) to give the selection area a margin/border.
