import java.util.*;

public class Convert_Units_Using_DFS {

    static class Input {
        String fromUnit;
        String toUnit;
        float multiplier;

        Input(String fromUnit, String toUnit, float multiplier) {
            this.fromUnit = fromUnit;
            this.toUnit = toUnit;
            this.multiplier = multiplier;
        }
    }

    private HashMap<String, LinkedList<HashMap<String, Float>>> adj;
    private StringBuilder multiplier;

    public Convert_Units_Using_DFS() {
        adj = new HashMap<>();
        multiplier = new StringBuilder("\nMultiplier: ");
    }

    public void addEdge(String fromUnit, String toUnit, float multiplier) {
        if (adj.containsKey(fromUnit)) {
            LinkedList<HashMap<String, Float>> list = adj.get(fromUnit);
            list.add(new HashMap<String, Float>() {
                {
                    put(toUnit, multiplier);
                }
            });
            adj.put(fromUnit, list);
        } else {
            LinkedList<HashMap<String, Float>> list = new LinkedList<>();
            list.add(new HashMap<String, Float>() {
                {
                    put(toUnit, multiplier);
                }
            });
            adj.put(fromUnit, list);

        }
        System.out.println(adj);
    }

    boolean DFSUtil(String fromString, HashMap<String, Boolean> visited, String findToUnit) {

        // Create a stack for DFS
        Stack<HashMap<String, Float>> stack = new Stack<>();
        HashMap<String, Float> map = new HashMap<>();
        map.put(fromString, 1f);

        // Push current vertex into stack
        stack.push(map);

        // Iterate until the stack gets empty
        while (!stack.empty()) {

            HashMap<String, Float> x = stack.peek();
            stack.pop();

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            String key = (String) x.keySet().toArray()[0];
            // System.out.println("key: " + key);
            if (!visited.get(key)) {
                // Mark the current node as visited and print
                System.out.print(key + " ");
                multiplier.append(x.get(key) + " * ");
                visited.put(key, true);
            }

            if (key == findToUnit) {
                System.out.println(multiplier.toString());
                return true;
            }

            // Get all adjacent vertices of the popped vertex x
            // If a adjacent has not been visited, then push it
            // to the stack.
            LinkedList<HashMap<String, Float>> list = adj.get(key) == null ? new LinkedList<>() : adj.get(key);
            for (HashMap<String, Float> item : list) {
                String key_ = (String) item.keySet().toArray()[0];
                if (!visited.get(key_)) {
                    stack.push(item);
                    // System.out.println("stack.push(key): " + item);
                }
            }
        }

        return false;
    }

    public void DFS(List<String> units, String findFromUnit, String findToUnit) {
        HashMap<String, Boolean> visited = new HashMap<>();

        Iterator<String> itr = units.iterator();

        while (itr.hasNext()) {
            visited.put(itr.next(), false);
        }

        // For Disjoint graph
        itr = units.iterator();
        boolean foundUnit = false;
        for (String key : units) {
            if (visited.get(key) == false) {
                foundUnit = DFSUtil(key, visited, findToUnit);
                if (foundUnit)
                    break;
            }
        }

        if (foundUnit)
            System.out.println("\nFound " + findToUnit);
        else
            System.out.println("\nNot Found " + findToUnit);
    }

    public static void main(String[] args) {

        List<Input> inputs = new ArrayList<>();
        inputs.add(new Input("feet", "inch", 12f));
        inputs.add(new Input("inch", "cm", 2.53f));
        inputs.add(new Input("yard", "cm", 91.44f));
        inputs.add(new Input("feet", "yard", 0.333333f));
        inputs.add(new Input("cm", "meter", 0.01f));
        // inputs.add(new Input("feet", "meter", 43f));
        // inputs.add(new Input("meter", "cm", 100f));

        Set<String> unitsSet = new HashSet<>();
        // Get the unique units
        for (Input input : inputs) {
            unitsSet.add(input.fromUnit);
            unitsSet.add(input.toUnit);
        }

        String findUnitFrom = "feet", findUnitTo = "cm";

        List<String> units = new ArrayList<>();
        units.add(findUnitFrom);
        Iterator<String> itr = unitsSet.iterator();
        while (itr.hasNext()) {
            String str = itr.next();
            if (str != findUnitFrom)
                units.add(str);
        }

        System.out.println(units);

        Convert_Units_Using_DFS dfs = new Convert_Units_Using_DFS();

        for (Input input : inputs) {
            dfs.addEdge(input.fromUnit, input.toUnit, input.multiplier);
        }
        System.out.println("Depth First Traversal:");

        dfs.DFS(units, findUnitFrom, findUnitTo);
    }
}