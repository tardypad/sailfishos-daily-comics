function(page) {
    var regex = /<img[^>]+src="(https:\/\/assets.amuniversal.com\/[0-9a-f]+)"/;
    var match = regex.exec(page);
    return match[1];
}
