# libpptx
Biblioteca para la lectura de archivos .pptx de MS PowerPoint

This is an implementation of the OpenXML format for PowerPoint documents, it was mainly used to generate HTML documents from .pptx documents, it was a real challenge given that it's near to impossible to do this with high fidelity with css's limitations.

To use it correctly the programmer needs to understand how OpenXML format works and be familiar with the parts of a power point document. To use this, you need

1. [libxml2](https://www.google.co.ve/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwi16oOL6rnTAhUJZCYKHYebD04QFggjMAA&url=http%3A%2F%2Fxmlsoft.org%2F&usg=AFQjCNH6UicY70qLDVGTEZCAGPdZzJSgFw&sig2=-IHVCxhDhz5I18ipv94Jhw) XML parsing library.
2. Some zip archive manipulation library, like [libarchive](http://www.libarchive.org/).
3. Of course, a c compiler with support for the c99 standard or newer.

The basic mechanism is to read the file representing a given part in the document with the zip archive manipulator and then pass the text to the libxml2 XML parser, the root node is then passed to libpptx's corresponding *new* function and then access to all the members that make up the targeted Complex Type is provided by means of accessor functions, suppose that `node` is the root node of a given *presentation.xml* file, then

    pptx_ct_p_presentation *pptx;
    pptx = pptx_ct_p_presentation_new(node);
    
will create a new presentation object, where `pptx_ct_p_presentation` is the c representation of the `CT_Presentation` complex type which belongs to the *p* namespace, as defined by the specs.

Only a single header is required *pptx.h*, and it cannot be included in another header file. If you think this is a bad decision and you have a good explanation of why, I can reconsider and fix it.

A pkg-config file is provided too to enable developers easy usage of this library.

Also, in the future it might be interesting to add write capability because for the moment it is only possible to read documents.
