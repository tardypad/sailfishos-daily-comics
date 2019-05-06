function(page) {
    var regex = /<figure\sitemscope="itemscope"\sitemtype="http:\/\/schema.org\/ImageObject"\sitemprop="image"\sclass="fjs-gallery-item"\sdata-hires="(https:\/\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
