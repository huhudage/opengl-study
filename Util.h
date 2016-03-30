//
//  Util.h
//  opengl-study
//
//  Created by lijinhu on 3/29/16.
//  Copyright © 2016 李金虎. All rights reserved.
//

#import <Foundation/Foundation.h>

unsigned char* loadImageFromBundle(NSString *imageName, NSString *imageType, int *width, int *height)
{
    NSString *filePath = [[NSBundle mainBundle] pathForResource:imageName ofType:imageType];
    unsigned char* image = SOIL_load_image(filePath.UTF8String, width, height, 0, SOIL_LOAD_RGB);
    if (image == NULL)
    {
        const char *result = SOIL_last_result();
        NSLog(@"load image result:%@", [NSString stringWithUTF8String:result]);
    }
    
    return image;
}
