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
            url: "https://github.com/diffusiondata/diffusion-sdk-apple/raw/6.8.3/Diffusion.xcframework.zip",
            checksum: "2ba0d65d24afa9c6d8e0c3270b16bbfc5684f80974a5592819fc58d70657ed58"
        )
    ]
)
