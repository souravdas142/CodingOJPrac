
class Node {
    public int key;
    public int value;
    
    public Node next;
    public Node prev;
    
    public Node() {}
    
    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

class LRUCache {
    
    private static Map<Integer,Node> mp;
    
    private static Node head;
    private static Node tail;
    private static int cap;
    private static int size;

    LRUCache(int capi) {
        // code here
        
        mp = new HashMap<Integer,Node>();
        head = new Node();
        tail = new Node();
        
        head.next = tail;
        tail.prev = head;
        
        cap = capi;
        size = 0;
        
    }
    
    public static void swap(Node node) {
        
        if(node.prev != null && node.next != null) {
            (node.prev).next = node.next;
            (node.next).prev = node.prev;
        }
        
        
        node.next = head.next;
        node.prev = head;
        (head.next).prev = node;
        
        head.next = node;
        // if(tail.prev == head)
        //     tail.prev = node;
        
    }
    
    public static void remove() {
        Node delNode = tail.prev;
        mp.remove(delNode.key);
        Node prevNode = delNode.prev;
        prevNode.next = tail;
        tail.prev = prevNode;
        delNode.next = null;
        delNode.prev = null;
        
    }
    
    public static void add(int key, int value) {
       
        
        if(size<cap) {
            size++;
            
        } else {
            remove();
            
        }
        
        Node newNode = new Node(key,value);
        
        update(newNode,-1);
        
        mp.put(key,newNode);
        
    }
    
    public static void update(Node node, int value) {
        if(value!=-1) {
            node.value = value;
        }
        
        swap(node);
    }
    
    

    public static int get(int key) {
        //  code here
        Node res = mp.getOrDefault(key,null);
        if(res==null) return -1;
        update(res,-1);
        return res.value;
    }

        
    public static void put(int key, int value) {
        //  code here
        Node res = mp.getOrDefault(key,null);
        if(res==null) {
            add(key,value);
        }
        else {
            update(res,value);
        }
    }
}