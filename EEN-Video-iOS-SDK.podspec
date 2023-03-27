#
# Be sure to run `pod lib lint EEN-Video-iOS-SDK.podspec' to ensure this is a
# valid spec before submitting.

Pod::Spec.new do |s|
  s.name             = 'EEN-Video-iOS-SDK'
  s.version          = '1.0'
  s.summary          = 'A video player designed to play files from EagleEye Networks.'
  s.license = { :type => 'Proprietary', :text => 'This binary is is not openly licensed to any individual without prior written permission and remains the property of EagleEye Networks, Inc.' }

  s.description      = 'A video player designed specifically to play files from EagleEye Networks.'
  s.homepage         = 'https://github.com/EENCloud/EEN-Video-iOS-SDK-Public/'
  s.author           = { 'David Huller' => 'dhuller@@een.com' }
  s.ios.deployment_target = '13.0'

  s.source = {
  	:http => 'https://github.com/EENCloud/EEN-Video-iOS-SDK-Public/blob/main/EEN_Video_iOS_SDK.zip?raw=true'
  }
  s.vendored_frameworks = 'EEN_Video_iOS_SDK.xcframework'
end
