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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.9.2/Diffusion.xcframework.zip",
            checksum: "ff3717f7d553e7c4f291ef76622150c9a1a73270db2bcf138e288331d2fe6f23"
        )
    ]
)
