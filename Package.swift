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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.10.0/Diffusion.xcframework.zip",
            checksum: "1bc8b8a40a8114e2d88db3a0c29e1d36561f35e3318675b64921d26512c1a949"
        )
    ]
)
