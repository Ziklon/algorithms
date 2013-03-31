function roundtrip_input(infile, figNr)
% infile = skyline.X.in
% figNr = FigureToPlotIn, e.g. 1
    if(nargin < 2)
        figNr = 1234;
    end

    fh = fopen(infile);
    numNodes = fscanf(fh, '%d', 1);
    numEdges = fscanf(fh, '%d', 1);
    node.x = 0;
    node.y = 0;
    nodes(1:numNodes) = node;
    for i=1:numNodes
        nodes(i).x = fscanf(fh, '%d', 1);
        nodes(i).y = fscanf(fh, '%d', 1);
    end
    edge.a = 0;
    edge.b = 0;
    edges(1:numEdges) = edge;
    for i=1:numEdges
        a = fscanf(fh, '%d', 1);
        b = fscanf(fh, '%d', 1);
        edges(i).a = a+1;
        edges(i).b = b+1;
    end
    fclose(fh);

    figure(figNr);
    x = [nodes.x];
    y = [nodes.y];
    plot([x([edges.a]); x([edges.b])],[y([edges.a]); y([edges.b])],'b-');
    hold('on');
    plot(x,y,'r+');
    hold('off');
end