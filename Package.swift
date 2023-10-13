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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.10.1/Diffusion.xcframework.zip",
            checksum: "99cc7cf401e5f44aa9a0bf692e0b1b499cdc7c6af5d7de1a644f47d64a457a3e"
        )
    ]
)
