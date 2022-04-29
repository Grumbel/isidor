{
  inputs = {
    nixpkgs.url = "github:Grumbel/nixpkgs?ref=fix-guile-3.0";
    # nixpkgs.url = "github:nixos/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";

    clanlib.url = "gitlab:grumbel/clanlib-1.0";
    clanlib.inputs.nixpkgs.follows = "nixpkgs";
    clanlib.inputs.flake-utils.follows = "flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, clanlib }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        packages = flake-utils.lib.flattenTree {
          isidor = pkgs.stdenv.mkDerivation rec {
            pname = "isidor";
            version = "0.1";
            src = nixpkgs.lib.cleanSource ./.;
            enableParallelBuilding = true;
            postPatch = ''
              substituteInPlace src/datadir.cpp \
                --replace '"data/"' '"'"''${out}"'/share/isidor"'
            '';
            postFixup = ''
              for program in $out/bin/*; do \
                wrapProgram "$program" \
                  --prefix LIBGL_DRIVERS_PATH ":" "${pkgs.mesa.drivers}/lib/dri" \
                  --prefix LD_LIBRARY_PATH ":" "${pkgs.mesa.drivers}/lib"; \
              done
            '';
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.swig
              pkgs.pkg-config
              pkgs.makeWrapper
            ];
            buildInputs = [
              clanlib.defaultPackage.${system}
            ];
           };
        };
        defaultPackage = packages.isidor;
      });
}
