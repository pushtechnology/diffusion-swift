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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.9.0/Diffusion.xcframework.zip",
            checksum: "0597f564169e0279f9a6b72939a90e7790e877d05386f9599a5a0d1995cec895"
        )
    ]
)
