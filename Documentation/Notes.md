# Escape O.D.T. Notes

Below is a collection of various notes related to the game
Escape O.D.T. which might prove useful.

## Bosses

All of the logic for each boss is retained in it's own
individual .bin file located under the root, so for example
'BOSS02.BIN' holds all the logic for the boss at the end of
the second level.

Unfortunately this means that the disassembly is currently 
missing the logic for these individual bosses.

The boss module is initialised under `Pvl_InitLevel` based
on which level is currently loaded.
