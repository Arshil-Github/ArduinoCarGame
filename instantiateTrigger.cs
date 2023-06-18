using UnityEngine;

public class instantiateTrigger : MonoBehaviour
{
    public Vector3 NextInstantiatePosition;
    public Transform initiateZPositionreference;
    public GameObject currentChunk;
    public GameObject Chunk;
    public GameObject previousChunk;
    // Start is called before the first frame update
    void Start()
    {
        NextInstantiatePosition.z = initiateZPositionreference.position.z;
    }
    private void OnTriggerEnter(Collider other)
    {
        GameObject a = Instantiate(Chunk, NextInstantiatePosition, Quaternion.identity);
        a.transform.Find("InstantiateTrigger").gameObject.GetComponent<instantiateTrigger>().previousChunk = currentChunk;

        Destroy(previousChunk);
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
