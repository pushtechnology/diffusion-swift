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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.8.5/Diffusion.xcframework.zip",
            checksum: "5aacc6001534c6008f2bf7e95c1b0cab7d3989b2f94dbed7394b6aebcf23e492"
        )
    ]
)
