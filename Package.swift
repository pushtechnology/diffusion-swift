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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.8.1/Diffusion.xcframework.zip",
            checksum: "ac5b4dd41de1a638bb9a786e585c2a7015b07ad56f0f4beb2c468c3cf9c2dd68"
        )
    ]
)
