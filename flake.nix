{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    flake-utils.url = "github:numtide/flake-utils";

    clanlib.url = "github:grumbel/clanlib-1.0";
    clanlib.inputs.nixpkgs.follows = "nixpkgs";
    clanlib.inputs.flake-utils.follows = "flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, clanlib }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        packages = rec {
          default = isidor;

          isidor = pkgs.stdenv.mkDerivation rec {
            pname = "isidor";
            version = "0.1";

            src = nixpkgs.lib.cleanSource ./.;

            enableParallelBuilding = true;

            postPatch = ''
              substituteInPlace src/datadir.cpp \
                --replace '"data/"' '"'"''${out}"'/share/isidor"'
            '';

            nativeBuildInputs = with pkgs; [
              cmake
              swig
              pkg-config
            ];

            buildInputs = [
              clanlib.packages.${system}.default
            ];
           };
        };
      }
    );
}
