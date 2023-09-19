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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.8.0/Diffusion.xcframework.zip",
            checksum: "75d719ae9515b24cae37ca36f9b215f154bd82b6c1685bc8c3c178d33bec8d4f"
        )
    ]
)
