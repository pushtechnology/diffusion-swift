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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.9.1/Diffusion.xcframework.zip",
            checksum: "3bdf6318119ca23a15b7c8537f2519905f436b8ee77ca0ac599de88cf4c90ea0"
        )
    ]
)
