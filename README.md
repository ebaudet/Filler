# Filler

`filler` is a player program for the 42 **Filler** project.

The program does not run as a standalone game. It is meant to be launched by the
provided virtual machine (`vm_beta.rb`), which sends the current board and the
next piece to each player through standard input. For every turn, this player
prints one coordinate (`row column`) on standard output.

## Goal

Two players compete on a rectangular board.

On each turn, the VM sends a randomly generated piece made of `*` cells. The
player must place that piece on the board with these rules:

- the piece must overlap exactly one cell already owned by the player;
- the piece must not overlap the opponent's cells;
- the piece may cover empty cells;
- if no valid move is possible, the player loses.

This implementation reads the VM protocol, stores the board and piece, then
prints the first valid position it finds while scanning the board.

## Repository Layout

- `src/` - main player source files.
- `includes/` - project headers.
- `libft/` - local C utility library used by the player.
- `maps/` - sample maps for the VM.
- `bin/` - sample opponent binaries.
- `vm_beta.rb` - Ruby virtual machine used to run matches.
- `auteur` - project author file.

## Build

Build the player with:

```sh
make
```

This creates the `filler` binary at the repository root.

Useful Make targets:

```sh
make clean   # remove object files
make fclean  # remove object files and the filler binary
make re      # rebuild from scratch
```

## Usage

Run `filler` through the VM:

```sh
ruby vm_beta.rb -f maps/map1.map -p1 ./filler -p2 bin/hcao.filler
```

Run this player as player 2:

```sh
ruby vm_beta.rb -f maps/map1.map -p1 bin/hcao.filler -p2 ./filler
```

Use quiet mode:

```sh
ruby vm_beta.rb -q -f maps/map2.map -p1 ./filler -p2 bin/superjeannot.filler
```

Use a fixed seed for reproducible games:

```sh
ruby vm_beta.rb -s 42 -f maps/map3.map -p1 ./filler -p2 bin/grati.filler
```

The VM options are:

```text
-f, --file         map file to use
-p1, --player1    binary used as player 1
-p2, --player2    binary used as player 2
-i, --interactive interactive mode
-q, --quiet       quiet mode
-s, --seed        random seed
-t, --time        timeout in seconds
```

## Input and Output Protocol

The VM first announces the player number:

```text
$$$ exec p1 : [./filler]
```

Then, for every turn, it sends:

```text
Plateau <rows> <columns>:
    012345...
000 .......
001 ...O...
...
Piece <rows> <columns>:
.*.
***
```

The player must answer with:

```text
<row> <column>
```

Example:

```text
4 7
```

Running `./filler` directly is only useful for checking that the binary starts.
Without VM input, it has no game state to process and exits without playing.

## Current Strategy

The current strategy is intentionally simple:

1. parse the board and current piece;
2. scan possible placements from the top-left of the board;
3. print the first valid coordinate;
4. print `0 0` if no valid coordinate is found.

This is enough to produce legal moves, but it is not an advanced strategy. Better
players usually score candidate moves by distance to the opponent, board control,
or heat maps.
