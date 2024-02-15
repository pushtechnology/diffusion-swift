// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Diffusion",
    products: [
        .library(
            name: "Diffusion",
            targets: [ "Diffusion" ]
        ),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Diffusion",
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.10.2/Diffusion.xcframework.zip",
            checksum: "3a3d6513bff031d299f3a43c1afde1fc72c151bd1a09be7df9a684ff3e34883f"
        )
    ]
)
