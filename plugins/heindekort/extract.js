function(page) {
    var regex = /<img[^>]*src="([^"]*)"/g;
    var match = regex.exec(page);
    var match2 = regex.exec(page);
    return match2[1].replace(/&amp;/g, '&');
}
