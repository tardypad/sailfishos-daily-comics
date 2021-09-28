function(page) {
//    var regex = /<img\ssrc="([^"]*)"/;
    var regex = /<source\ssrcset="([^"]*)"\stype="image\/jpeg">/;
    var match = regex.exec(page);
    return match[1].replace('&amp;', '&');
//    return match[1].replace('\/thumbs', '');
}
